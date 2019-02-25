/*
 * EntityMgr.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */
#include "EntityMgr.h"

EntityMgr::EntityMgr()
{
	//do nothing
}

EntityMgr::EntityMgr(Ogre::SceneManager* mgr)
{
	mScnMgr = mgr;
	//entities = new std::vector<Entity381*>;
}

EntityMgr::~EntityMgr()
{
	//do nothing
}

void EntityMgr::Tick(float dt)
{
	for(int i=0 ; i<entities.size() ; i++)
	{
		entities.at(i)->Tick(dt);
	}
}

void EntityMgr::createEntity(bool obj, std::string name, Ogre::Vector3 pos)
{
	Ogre::Vector3 position = Ogre::Vector3(pos.x,pos.y,pos.z);
	Entity381* newEnt = new Entity381(mScnMgr, obj, name, position);

	entities.push_back(newEnt);

	if(entities.size() == 1)
	{
		Renderable *temp = (Renderable*) entities.at(mIndex)->getAspect(0);
		temp->showBox(true);
		entities.at(mIndex)->isSelected = true;
	}
}

void EntityMgr::destroyEntity()
{
	//do nothing
}

Entity381* EntityMgr::getEntity()
{
	return entities.at(mIndex);
}

void EntityMgr::enumerateIndex()
{
	Renderable *temp = (Renderable*) entities.at(mIndex)->getAspect(0);
	temp->showBox(false);
	entities.at(mIndex)->isSelected = true;

	mIndex = (mIndex + 1) % entities.size();

	temp = (Renderable*) entities.at(mIndex)->getAspect(0);
	temp->showBox(true);
	entities.at(mIndex)->isSelected = true;
}
