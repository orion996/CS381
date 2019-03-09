/*
 * InputMgr.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: orion996
 */

#include "InputMgr.h"

InputMgr::InputMgr(OIS::InputManager* imgr, OIS::Mouse* ms, OIS::Keyboard* kb, Ogre::RenderWindow* win, Engine* eng)
{
	mInputMgr = imgr;
	mMouse = ms;
	mKeyboard = kb;
	mWindow = win;
	mEngine = eng;
}

InputMgr::~InputMgr()
{

}

bool InputMgr::Init()
{

	Ogre::LogManager::getSingletonPtr()->logMessage("*** Initializing OIS ***");

	  OIS::ParamList pl;
	  size_t windowHandle = 0;
	  std::ostringstream windowHandleStr;

	  mWindow->getCustomAttribute( "WINDOW", &windowHandle );

	// Fill parameter list
	windowHandleStr << (size_t) windowHandle;
	pl.insert( std::make_pair( std::string( "WINDOW" ), windowHandleStr.str() ) );

	  mInputMgr = OIS::InputManager::createInputSystem(pl);

	  mKeyboard = static_cast<OIS::Keyboard*>(
	    mInputMgr->createInputObject(OIS::OISKeyboard, false));
	  mMouse = static_cast<OIS::Mouse*>(
	    mInputMgr->createInputObject(OIS::OISMouse, false));

	  //Addresses in Engine were being overwritten; set them to current addresses AFTER assignment
	  mEngine->setInputMembers(mInputMgr, mMouse, mKeyboard);

	  windowResized(mWindow);
	  Ogre::WindowEventUtilities::addWindowEventListener(mWindow, this);

	return true;
}

void InputMgr::Tick(float dt)
{

}

void InputMgr::windowClosed(Ogre::RenderWindow* rw)
{
    //Only close for window that created OIS (the main window in these demos)
    if(rw == mWindow)
    {
        if(mInputMgr)
        {
            mInputMgr->destroyInputObject( mMouse );
            mInputMgr->destroyInputObject( mKeyboard );

            OIS::InputManager::destroyInputSystem(mInputMgr);
            mInputMgr = 0;
        }
    }
}

void InputMgr::windowResized(Ogre::RenderWindow* rw)
{
    unsigned int width, height, depth;
    int left, top;
    rw->getMetrics(width, height, depth, left, top);

    const OIS::MouseState &ms = mMouse->getMouseState();
    ms.width = width;
    ms.height = height;
}

bool InputMgr::processUnbufferedInput(const Ogre::FrameEvent& fe)
{
	mKeyboard->capture();
	mMouse->capture();

	Ogre::Vector3 camVec = Ogre::Vector3::ZERO;
	const float camMove = 200.0;
	const float camRot = 150.0;
	float dt = 0;

	//EXIT
	if(mKeyboard->isKeyDown(OIS::KC_ESCAPE)) return false;

	dt = fe.timeSinceLastFrame;

	//CAMERA
	if(mKeyboard->isKeyDown(OIS::KC_W))//camera forward
	{
		camVec = Ogre::Vector3::ZERO;
		camVec.z -= camMove * dt;
		mEngine->getGfxMgr()->setCameraPosition(camVec);
	}
	if(mKeyboard->isKeyDown(OIS::KC_S))//camera backwards
	{
		camVec = Ogre::Vector3::ZERO;
		camVec.z += camMove * dt;
		mEngine->getGfxMgr()->setCameraPosition(camVec);
	}
	if(mKeyboard->isKeyDown(OIS::KC_A))//camera left
	{
		if(mKeyboard->isKeyDown(OIS::KC_LSHIFT))//camera rotate
		{
			mEngine->getGfxMgr()->yawCamera(-1 * (camRot*dt));
		}
		else
		{
			camVec = Ogre::Vector3::ZERO;
			camVec.x -= camMove * dt;
			mEngine->getGfxMgr()->setCameraPosition(camVec);
		}
	}
	if(mKeyboard->isKeyDown(OIS::KC_D))//camera right
	{
		if(mKeyboard->isKeyDown(OIS::KC_LSHIFT))//camera rotate
		{
			mEngine->getGfxMgr()->yawCamera((camRot*dt));
		}
		else
		{
			camVec = Ogre::Vector3::ZERO;
			camVec.x += camMove * dt;
			mEngine->getGfxMgr()->setCameraPosition(camVec);
		}
	}
	if(mKeyboard->isKeyDown(OIS::KC_PGUP))//camera up
	{
		if(mKeyboard->isKeyDown(OIS::KC_LSHIFT))//camera rotate
		{
			mEngine->getGfxMgr()->pitchCamera(-1 * (camRot*dt));
		}
		else
		{
			camVec = Ogre::Vector3::ZERO;
			camVec.y += camMove * dt;
			mEngine->getGfxMgr()->setCameraPosition(camVec);
		}
	}
	if(mKeyboard->isKeyDown(OIS::KC_PGDOWN))//camera down
	{
		if(mKeyboard->isKeyDown(OIS::KC_LSHIFT))//camera rotate
		{
			mEngine->getGfxMgr()->pitchCamera((camRot*dt));
		}
		else
		{
			camVec = Ogre::Vector3::ZERO;
			camVec.y -= camMove * dt;
			mEngine->getGfxMgr()->setCameraPosition(camVec);
		}
	}

	//ENTITY CONTROLS
	mTimer -= dt;
	static float speed = 0;
	static float heading = 0;
	static const float spdConst = 5.0;
	static const float headConst = 0.1;

	if(mKeyboard->isKeyDown(OIS::KC_TAB) && mTimer < 0)//change selected entity
	{
		mEngine->getEntityMgr()->enumerateIndex();
		mTimer = 0.2;
	}

	if(mKeyboard->isKeyDown(OIS::KC_UP) && mTimer < 0)//entity speed up
	{
		//get current desired speed
		speed = mEngine->getEntityMgr()->getEntity()->getSpeed();

		//add to current speed -> new desired speed
		speed += spdConst;

		//set new desired speed
		mEngine->getEntityMgr()->getEntity()->setDesiredSpeed(speed);

		//reset toggle timer
		mTimer = 0.2;
	}
	if(mKeyboard->isKeyDown(OIS::KC_DOWN) && mTimer < 0)//entity speed down
	{
		//get current desired speed
		speed = mEngine->getEntityMgr()->getEntity()->getSpeed();

		//add to current speed -> new desired speed
		speed -= spdConst;

		//set new desired speed
		mEngine->getEntityMgr()->getEntity()->setDesiredSpeed(speed);

		//reset toggle timer
		mTimer = 0.2;
	}
	if(mKeyboard->isKeyDown(OIS::KC_LEFT) && mTimer < 0)//entity turn left
	{
		//get current desired heading
		heading = mEngine->getEntityMgr()->getEntity()->getHeading();

		//add to current heading -> new desired heading
		heading -= headConst;

		//set new desired heading
		mEngine->getEntityMgr()->getEntity()->setDesiredHeading(heading);

		//reset toggle timer
		mTimer = 0.2;
	}
	if(mKeyboard->isKeyDown(OIS::KC_RIGHT) && mTimer < 0)//entity turn right
	{
		//get current desired heading
		heading = mEngine->getEntityMgr()->getEntity()->getHeading();

		//add to current heading -> new desired heading
		heading += headConst;

		//set new desired heading
		mEngine->getEntityMgr()->getEntity()->setDesiredHeading(heading);

		//reset toggle timer
		mTimer = 0.2;
	}
	if(mKeyboard->isKeyDown(OIS::KC_SPACE) && mTimer < 0)//entity speed zero
	{
		mEngine->getEntityMgr()->getEntity()->setDesiredSpeed(0);

		//reset toggle timer
		mTimer = 0.2;
	}

	//Move the Entity
	mEngine->getEntityMgr()->getEntity()->orientedMove();



	return true;
}
