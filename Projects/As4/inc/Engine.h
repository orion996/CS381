/*
 * Engine.h
 *
 *  Created on: Mar 7, 2019
 *      Author: orion996
 */

#ifndef INC_ENGINE_H_
#define INC_ENGINE_H_

#include "GfxMgr.h"
#include "GameMgr.h"
#include "InputMgr.h"
#include "EntityMgr.h"

class GfxMgr;
class GameMgr;
class InputMgr;
class EntityMgr;

class Engine : public Ogre::FrameListener
{
public:
	Engine();
	~Engine();

	bool Init();
	void Run();

	virtual bool frameRenderingQueued(const Ogre::FrameEvent& fe);

	void setInputMembers(OIS::InputManager*, OIS::Mouse*, OIS::Keyboard*);
	void setWindowMember(Ogre::RenderWindow*);

	GfxMgr* getGfxMgr();
	EntityMgr* getEntityMgr();

private:
	GfxMgr* mGfxMgr;
	GameMgr* mGameMgr;
	InputMgr* mInputMgr;
	EntityMgr* mEntityMgr;

	Ogre::Root* mRoot;
	Ogre::String mResourcesCfg;
	Ogre::String mPluginsCfg;
	Ogre::RenderWindow* mWindow;
	Ogre::SceneManager* mSceneMgr;
	Ogre::Camera* mCamera;

	OIS::InputManager* mInput;
	OIS::Keyboard* mKeyboard;
	OIS::Mouse* mMouse;

	float mTimer = 0.0;

};

#endif /* INC_ENGINE_H_ */
