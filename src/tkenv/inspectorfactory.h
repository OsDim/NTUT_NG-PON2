//==========================================================================
//  INSPECTORFACTORY.H - part of
//
//                     OMNeT++/OMNEST
//            Discrete System Simulation in C++
//
//==========================================================================

/*--------------------------------------------------------------*
  Copyright (C) 1992-2008 Andras Varga
  Copyright (C) 2006-2008 OpenSim Ltd.

  This file is distributed WITHOUT ANY WARRANTY. See the file
  `license' for details on this and other legal matters.
*--------------------------------------------------------------*/

#ifndef __INSPECTORFACTORY_H
#define __INSPECTORFACTORY_H

#include <tk.h>
#include "onstartup.h"
#include "cregistrationlist.h"
#include "inspector.h"
#include "envirbase.h"

NAMESPACE_BEGIN

#define Register_InspectorFactory(FACTORYNAME) \
  EXECUTE_ON_STARTUP(inspectorfactories.getInstance()->add(new FACTORYNAME(#FACTORYNAME));)


/**
 * Serves as a base class for inspector factories of specific classes.
 */
class TKENV_API InspectorFactory : public cNoncopyableOwnedObject
{
  public:
    /** @name Constructors, destructor, assignment. */
    //@{
    /**
     * Constructor.
     */
    InspectorFactory(const char *name) : cNoncopyableOwnedObject(name,false) {}

    /**
     * Destructor.
     */
    virtual ~InspectorFactory() {}
    //@}


    /** @name Inspector creation. */
    //@{
    /**
     * Returns true if this factory can create an inspector for this object.
     */
    virtual bool supportsObject(cObject *object) = 0;

    /**
     * Returns type of inspector created by this factory (INSP_* constants).
     */
    virtual int getInspectorType() = 0;

    /**
     * Returns "how good" this inspector is as default inspector for this object;
     * a higher value is better.
     */
    virtual double getQualityAsDefault(cObject *object) = 0;

    /**
     * Creates an inspector.
     */
    virtual Inspector *createInspector() = 0;
    //@}

    /**
     * Finds an inspector factory by name. Returns NULL if not found.
     */
    static InspectorFactory *find(const char *className);

    /**
     * Finds an inspector factory by name. Throws an error if not found.
     */
    static InspectorFactory *get(const char *className);

};

///< List of cInspectorFactory objects.
extern cGlobalRegistrationList inspectorfactories;

/**
 * Find a cInspectorFactory.
 */
InspectorFactory *findInspectorFactoryFor(cObject *obj, int type);

NAMESPACE_END


#endif



