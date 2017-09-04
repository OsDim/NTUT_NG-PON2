//
// Generated file, do not edit! Created by nedtool 4.6 from traffic_gen/Messages/MyPacket.msg.
//

#ifndef _MYPACKET_M_H_
#define _MYPACKET_M_H_

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0406
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif



// cplusplus {{
#include <inttypes.h>
// }}

/**
 * Class generated from <tt>traffic_gen/Messages/MyPacket.msg:21</tt> by nedtool.
 * <pre>
 * packet GrantMsg
 * {
 *     int GrantLen;	// gate size
 * }
 * </pre>
 */
class GrantMsg : public ::cPacket
{
  protected:
    int GrantLen_var;

  private:
    void copy(const GrantMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const GrantMsg&);

  public:
    GrantMsg(const char *name=NULL, int kind=0);
    GrantMsg(const GrantMsg& other);
    virtual ~GrantMsg();
    GrantMsg& operator=(const GrantMsg& other);
    virtual GrantMsg *dup() const {return new GrantMsg(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getGrantLen() const;
    virtual void setGrantLen(int GrantLen);
};

inline void doPacking(cCommBuffer *b, GrantMsg& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, GrantMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>traffic_gen/Messages/MyPacket.msg:26</tt> by nedtool.
 * <pre>
 * packet RespMsg
 * {
 *     int QueueLen;	// data bytes in queue
 * }
 * </pre>
 */
class RespMsg : public ::cPacket
{
  protected:
    int QueueLen_var;

  private:
    void copy(const RespMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const RespMsg&);

  public:
    RespMsg(const char *name=NULL, int kind=0);
    RespMsg(const RespMsg& other);
    virtual ~RespMsg();
    RespMsg& operator=(const RespMsg& other);
    virtual RespMsg *dup() const {return new RespMsg(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual int getQueueLen() const;
    virtual void setQueueLen(int QueueLen);
};

inline void doPacking(cCommBuffer *b, RespMsg& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, RespMsg& obj) {obj.parsimUnpack(b);}

/**
 * Class generated from <tt>traffic_gen/Messages/MyPacket.msg:31</tt> by nedtool.
 * <pre>
 * packet TimeOutMsg
 * {
 *     uint16_t onuIdx;
 * }
 * </pre>
 */
class TimeOutMsg : public ::cPacket
{
  protected:
    uint16_t onuIdx_var;

  private:
    void copy(const TimeOutMsg& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const TimeOutMsg&);

  public:
    TimeOutMsg(const char *name=NULL, int kind=0);
    TimeOutMsg(const TimeOutMsg& other);
    virtual ~TimeOutMsg();
    TimeOutMsg& operator=(const TimeOutMsg& other);
    virtual TimeOutMsg *dup() const {return new TimeOutMsg(*this);}
    virtual void parsimPack(cCommBuffer *b);
    virtual void parsimUnpack(cCommBuffer *b);

    // field getter/setter methods
    virtual uint16_t getOnuIdx() const;
    virtual void setOnuIdx(uint16_t onuIdx);
};

inline void doPacking(cCommBuffer *b, TimeOutMsg& obj) {obj.parsimPack(b);}
inline void doUnpacking(cCommBuffer *b, TimeOutMsg& obj) {obj.parsimUnpack(b);}


#endif // ifndef _MYPACKET_M_H_

