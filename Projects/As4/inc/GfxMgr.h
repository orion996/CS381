/*
 * GfxMgr.h
 *
 *  Created on: Mar 7, 2019
 *      Author: orion996
 */

#ifndef INC_GFXMGR_H_
#define INC_GFXMGR_H_

#include "Mgr.h"

#include <OgreRoot.h>
#include <OgreWindowEventUtilities.h>

#include <OISEvents.h>
#include <OISInputManager.h>
#include <OISKeyboard.h>
#include <OISMouse.h>

#include <OgreVector3.h>

#include "Engine.h"
class Engine;

class GfxMgr : public MGR
{
public:
	GfxMgr(Ogre::Root*, Ogre::SceneManager*, Ogre::RenderWindow*, Engine*);
	virtual ~GfxMgr();

	bool Init();
    void Tick(float);

	void setCameraPosition(Ogre::Vector3);
	Ogre::Vector3 getCameraPosition();
	void yawCamera(float);
	void pitchCamera(float);

	void createCamera();
	void createScene();

private:
	 Ogre::Root* mRoot;
	 Ogre::String mResourcesCfg;
	 Ogre::String mPluginsCfg;
	 Ogre::RenderWindow* mWindow;
	 Ogre::SceneManager* mSceneMgr;
	 Ogre::Camera* mCamera;

	 OIS::InputManager* mInputMgr;
	 OIS::Keyboard* mKeyboard;
	 OIS::Mouse* mMouse;

//	 Engine* mEngine;


};



#endif /* INC_GFXMGR_H_ */
