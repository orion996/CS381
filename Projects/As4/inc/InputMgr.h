/*
 * InputMgr.h
 *
 *  Created on: Mar 7, 2019
 *      Author: orion996
 */

#ifndef INC_INPUTMGR_H_
#define INC_INPUTMGR_H_

#include "Mgr.h"

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>
#include <OgreRenderWindow.h>

#include <OgreVector3.h>

#include "Engine.h"
class Engine;

class InputMgr : MGR
{
public:
	InputMgr(OIS::InputManager*, OIS::Mouse*, OIS::Keyboard*, Ogre::RenderWindow*, Engine*);
	virtual ~InputMgr();

	void Tick(float);
	bool Init();

	bool processUnbufferedInput(const Ogre::FrameEvent&);

	virtual void windowResized(Ogre::RenderWindow* rw);
	virtual void windowClosed(Ogre::RenderWindow* rw);

private:
	OIS::InputManager* mInputMgr;
	OIS::Mouse* mMouse;
	OIS::Keyboard* mKeyboard;
	Ogre::RenderWindow* mWindow;

	float mTimer = 0.0;

//	Engine* mEngine;
};



#endif /* INC_INPUTMGR_H_ */
