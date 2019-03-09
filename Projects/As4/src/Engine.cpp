#include "Engine.h"

#include <OgreEntity.h>
#include <OgreCamera.h>
#include <OgreViewport.h>
#include <OgreSceneManager.h>
#include <OgreRenderWindow.h>
#include <OgreConfigFile.h>
#include <OgreException.h>

Engine::Engine() :
	mRoot(0),
    mResourcesCfg(Ogre::StringUtil::BLANK),
    mPluginsCfg(Ogre::StringUtil::BLANK),
    mInputMgr(0),
	mSceneMgr(0),
    mMouse(0),
    mKeyboard(0),
	mWindow(0)
{
	mGfxMgr = NULL;
	mGameMgr = NULL;
}

Engine::~Engine()
{

}

bool Engine::Init()
{
#ifdef _DEBUG
	  mResourcesCfg = "resources_d.cfg";
	  mPluginsCfg = "plugins_d.cfg";
	#else
	  mResourcesCfg = "resources.cfg";
	  mPluginsCfg = "plugins.cfg";
	#endif

	  mRoot = new Ogre::Root(mPluginsCfg);

	  Ogre::ConfigFile cf;
	  cf.load(mResourcesCfg);

	  Ogre::String name, locType;
	  Ogre::ConfigFile::SectionIterator secIt = cf.getSectionIterator();

	  while (secIt.hasMoreElements())
	  {
		Ogre::ConfigFile::SettingsMultiMap* settings = secIt.getNext();
		Ogre::ConfigFile::SettingsMultiMap::iterator it;

		for (it = settings->begin(); it != settings->end(); ++it)
		{
		  locType = it->first;
		  name = it->second;

		  Ogre::ResourceGroupManager::getSingleton().addResourceLocation(name, locType);
		}
	  }

	  if (!(mRoot->restoreConfig() || mRoot->showConfigDialog()))
		return false;

	  //Create Scene Manager
	  mSceneMgr = mRoot->createSceneManager(Ogre::ST_GENERIC);

	  //Entity Manager
	  mEntityMgr = new EntityMgr(mSceneMgr, this);

	  //Graphics Manager
	  mGfxMgr = new GfxMgr(mRoot, mSceneMgr, mWindow, this);
	  if(!mGfxMgr->Init()) return false;

	  //Game Manager
	  mGameMgr = new GameMgr(mSceneMgr, this);
	  if(!mGameMgr->Init()) return false;

	  //Input Manager
	  mInputMgr = new InputMgr(mInput, mMouse, mKeyboard, mWindow, this);
	  if(!mInputMgr->Init()) return false;



	  mRoot->addFrameListener(this);
}

void Engine::Run()
{
//	mRoot->startRendering(); //one line infinite loop for Ogre

	while(true)
	{
	  Ogre::WindowEventUtilities::messagePump();
	  if(!mRoot->renderOneFrame()) return;
	}


}

bool Engine::frameRenderingQueued(const Ogre::FrameEvent& fe)
{
	Ogre::LogManager::getSingletonPtr()->logMessage("*** Inside Frame Listener ***");
	  if (mWindow->isClosed()) return false;

	  if(!mInputMgr->processUnbufferedInput(fe)) return false;

	  mEntityMgr->Tick(fe.timeSinceLastFrame);

	  //Safety Timer for when working on input; shuts down program after 3 sec so I dont have to hardboot
//	  mTimer += fe.timeSinceLastFrame;
//	  if(mTimer >= 3) return false;
	return true;
}


void Engine::setInputMembers(OIS::InputManager* imgr, OIS::Mouse* ms, OIS::Keyboard* kb)
{
	mKeyboard = kb;
	mMouse = ms;
	mInput = imgr;
}

void Engine::setWindowMember(Ogre::RenderWindow* rwnd)
{
	mWindow = rwnd;
}

GfxMgr* Engine::getGfxMgr()
{
	return mGfxMgr;
}

EntityMgr* Engine::getEntityMgr()
{
	return mEntityMgr;
}
