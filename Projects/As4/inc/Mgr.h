/*
 * Mgr.h
 *
 *  Created on: Mar 7, 2019
 *      Author: orion996
 */

#ifndef INC_MGR_H_
#define INC_MGR_H_

#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

//#include "Engine.h"

class Engine;

class MGR : public Ogre::FrameListener, public Ogre::WindowEventListener
{
public:
	MGR();
	virtual ~MGR();

	bool Init();
	void Tick(float);

	Engine* mEngine;
};



#endif /* INC_MGR_H_ */
