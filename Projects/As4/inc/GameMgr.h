/*
 * GameMgr.h
 *
 *  Created on: Mar 8, 2019
 *      Author: orion996
 */

#ifndef INC_GAMEMGR_H_
#define INC_GAMEMGR_H_

#include "Mgr.h"

#include <OgreEntity.h>
#include <OgreSceneManager.h>
#include <OgreMeshManager.h>

#include "Engine.h"
class Engine;

class GameMgr : MGR
{
public:
	GameMgr(Ogre::SceneManager*, Engine*);
	virtual ~GameMgr();

	bool Init();

	void makeEntities();
	void makeSky();
	void makeGround(float);
	void makeLight();

private:
	Ogre::SceneManager* mSceneMgr;
//	Engine* mEngine;
};



#endif /* INC_GAMEMGR_H_ */
