/*
 * GfxMgr.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: orion996
 */

#include "GfxMgr.h"
//#include "Engine.h"

#include <OgreEntity.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include <OgreException.h>

GfxMgr::GfxMgr(Ogre::Root* root, Ogre::SceneManager* smgr, Ogre::RenderWindow* window, Engine* eng):
    mCamera(0)
{
	mRoot = root;
	mSceneMgr = smgr;
	mWindow = window;
	mEngine = eng;
}

GfxMgr::~GfxMgr()
{
//	Ogre::WindowEventUtilities::removeWindowEventListener(mWindow, this);
//
//	windowClosed(mWindow);
//
//	delete mRoot;
}

bool GfxMgr::Init()
{
	  //Create Window
	  mWindow = mRoot->initialise(true, "TutorialApplication Render Window");

	  mEngine->setWindowMember(mWindow);

	  //mgrs
	  Ogre::TextureManager::getSingleton().setDefaultNumMipmaps(5);
	  Ogre::ResourceGroupManager::getSingleton().initialiseAllResourceGroups();

	  //create Camera
	  this->createCamera();

	  return true;

}

void GfxMgr::createCamera()
{
	 mCamera = mSceneMgr->createCamera("MainCam");
	 mCamera->setPosition(0, 0, 80);
	 mCamera->lookAt(0, 0, -300);
	 mCamera->setNearClipDistance(5);

	 Ogre::Viewport* vp = mWindow->addViewport(mCamera);
	 vp->setBackgroundColour(Ogre::ColourValue(0, 0, 0));

	 mCamera->setAspectRatio(
	 Ogre::Real(vp->getActualWidth()) /
	 Ogre::Real(vp->getActualHeight()));
}

void GfxMgr::Tick(float dt)
{
	mRoot->renderOneFrame();
}

void GfxMgr::setCameraPosition(Ogre::Vector3 pos)
{
	mCamera->moveRelative(pos);
}

Ogre::Vector3 GfxMgr::getCameraPosition()
{
	return mCamera->getPosition();
}

void GfxMgr::yawCamera(float rotVal)
{
	mSceneMgr->getCamera("MainCam")->yaw(Ogre::Degree(rotVal * -1));
}

void GfxMgr::pitchCamera(float rotVal)
{
	mSceneMgr->getCamera("MainCam")->pitch(Ogre::Degree(rotVal * -1));
}





