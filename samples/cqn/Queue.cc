//
// This file is part of an OMNeT++/OMNEST simulation example.
//
// Copyright (C) 1992-2008 Andras Varga
//
// This file is distributed WITHOUT ANY WARRANTY. See the file
// `license' for details on this and other legal matters.
//


#include <omnetpp.h>

/**
 * Abstract base class for single-server queues. Subclasses are
 * expected to redefine the arrival(), startService() and endService()
 * methods.
 */
class AbstractQueue : public cSimpleModule
{
  protected:
    short int priority;
    cMessage *msgServiced;
    cMessage *endServiceMsg;
    cQueue queue;
    cOutVector queueLength;

  public:
    AbstractQueue();
    virtual ~AbstractQueue();

  protected:
    virtual void initialize();
    virtual void handleMessage(cMessage *msg);

    // hook functions to (re)define behaviour
    virtual void arrival(cMessage *msg) {}
    virtual simtime_t startService(cMessage *msg) = 0;
    virtual void endService(cMessage *msg) = 0;
};

AbstractQueue::AbstractQueue()
{
    msgServiced = endServiceMsg = NULL;
}

AbstractQueue::~AbstractQueue()
{
    delete msgServiced;
    cancelAndDelete(endServiceMsg);
}

void AbstractQueue::initialize()
{
    priority = par("priority");
    endServiceMsg = new cMessage("end-service");
    queue.setName("queue");
    queueLength.setName("queueLength");
}

void AbstractQueue::handleMessage(cMessage *msg)
{
    if (msg==endServiceMsg)
    {
        endService( msgServiced );
        if (queue.empty())
        {
            msgServiced = NULL;
            if (ev.isGUI()) getDisplayString().setTagArg("i",1,"");
        }
        else
        {
            msgServiced = (cMessage *) queue.pop();
            queueLength.record(queue.length());
            simtime_t serviceTime = startService( msgServiced );
            endServiceMsg->setSchedulingPriority(priority);
            scheduleAt( simTime()+serviceTime, endServiceMsg );
        }
    }
    else if (!msgServiced)
    {
        if (ev.isGUI()) getDisplayString().setTagArg("i",1,"gold3");

        arrival( msg );
        msgServiced = msg;
        simtime_t serviceTime = startService( msgServiced );
        endServiceMsg->setSchedulingPriority(priority);
        scheduleAt( simTime()+serviceTime, endServiceMsg );
    }
    else
    {
        arrival( msg );
        queue.insert( msg );
        queueLength.record(queue.length());
    }
}

//------------------------------------------------

/**
 * Queue model, with service time as parameter; see NED file for more info.
 */
class Queue: public AbstractQueue
{
  public:
    virtual void initialize();

    virtual simtime_t startService(cMessage *msg);
    virtual void endService(cMessage *msg);
};

Define_Module(Queue);

void Queue::initialize()
{
    AbstractQueue::initialize();

    long numInitialJobs = par("numInitialJobs");
    for (long i=0; i<numInitialJobs; i++)
    {
        cMessage *job = new cMessage("job");
        queue.insert(job);
        queueLength.record(queue.length());
    }

    if (!queue.empty())
    {
        msgServiced = (cMessage *) queue.pop();
        queueLength.record(queue.length());
        simtime_t serviceTime = startService( msgServiced );
        scheduleAt( simTime()+serviceTime, endServiceMsg );

        if (ev.isGUI()) getDisplayString().setTagArg("i",1,"gold3");
    }
}

simtime_t Queue::startService(cMessage *msg)
{
    EV << "Starting service of " << msg->getName() << endl;
    return par("serviceTime").doubleValue();
}

void Queue::endService(cMessage *msg)
{
    EV << "Completed service of " << msg->getName() << endl;
    msg->setSchedulingPriority(priority);
    send( msg, "out" );
}


