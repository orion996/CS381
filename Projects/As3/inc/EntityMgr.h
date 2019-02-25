/*
 * EntityMgr.h
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */

#ifndef INC_ENTITYMGR_H_
#define INC_ENTITYMGR_H_

#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <vector>

#include "Entity381.h"

class EntityMgr
{
public:
	EntityMgr();
	EntityMgr(Ogre::SceneManager*);
	~EntityMgr();

	void Tick(float dt);

	void createEntity(bool, std::string, Ogre::Vector3);
	void destroyEntity();

	void enumerateIndex();

	Entity381* getEntity();

private:
	std::vector<Entity381 *> entities;
	Ogre::SceneManager* mScnMgr;
	int mIndex = 0;

};



#endif /* INC_ENTITYMGR_H_ */
