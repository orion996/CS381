/*
 * EntityMgr.h
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */

#ifndef INC_ENTITYMGR_H_
#define INC_ENTITYMGR_H_

#include "Mgr.h"

#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <vector>
#include <string>

#include "Entity381.h"

#include "Engine.h"
class Engine;

class EntityMgr : MGR
{
public:
	EntityMgr();
	EntityMgr(Ogre::SceneManager*, Engine*);
	~EntityMgr();

	void Tick(float dt);

	void createEntity(std::string, std::string, Ogre::Vector3);
	void destroyEntity();

	void enumerateIndex();

	Entity381* getEntity();

private:
	std::vector<Entity381 *> entities;
	Ogre::SceneManager* mScnMgr;
	int mIndex = 0;
//	Engine* mEngine;

};



#endif /* INC_ENTITYMGR_H_ */
