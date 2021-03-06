/*
 * Entity381.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */
#include "Entity381.h"

Entity381::Entity381()
{
	//do nothing
}

Entity381::Entity381(Ogre::SceneManager* mgr, std::string objType, std::string name, Ogre::Vector3 pos)
{
	mScnMgr = mgr;
	Ogre::Vector3* position = new Ogre::Vector3(pos.x,pos.y,pos.z);
	mPos = position;
	mName = name;

	//aspects = new std::vector<Aspect*>;

	Renderable* renderable = new Renderable(mPos, mScnMgr, objType, mName);
	mScnNode = renderable->getSceneNode();
	this->addAspect(renderable);//renderable at index 0

	Physics* physics = new Physics(mPos);
	this->addAspect(physics);//physics at index 1

	Rotator* rotator = new Rotator(mScnNode);
	this->addAspect(rotator);//rotator at index 2

}

Entity381::~Entity381()
{
	//do nothing
}

void Entity381::Tick(float dt)
{
	for (int i=aspects.size()-1 ; i >=0 ; i--)
	{
		aspects.at(i)->Tick(dt);
	}
}

void Entity381::addAspect(Aspect* asp)
{
	aspects.push_back(asp);
}

void Entity381::setPosition(Ogre::Vector3 pos)
{
	mPos->x = pos.x;
	mPos->y = pos.y;
	mPos->z = pos.z;
}

Aspect* Entity381::getAspect(int index)
{
	return aspects.at(index);
}

