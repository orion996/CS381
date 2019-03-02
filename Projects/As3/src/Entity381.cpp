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
	mVelocity = new Ogre::Vector3(0,0,0);

	//aspects = new std::vector<Aspect*>;

	Renderable* renderable = new Renderable(mPos, mScnMgr, objType, mName);
	mScnNode = renderable->getSceneNode();
	this->addAspect(renderable);//renderable at index 0


	mSpeed = new float;
	*mSpeed = 0;
	mHeading = new float;
	*mHeading = 0;
	mAcceleration = new float;
	mTurnRate = new float;
	mDesiredHeading = new float;
	*mDesiredHeading = 0;
	mDesiredSpeed = new float;
	*mDesiredSpeed = 0;

	if(objType == "SAILBOAT")
	{
		*mAcceleration = 1.0;
		*mTurnRate = 0.001;
	}
	else if(objType == "CIG")
	{
		*mAcceleration = 5.0;
		*mTurnRate = 0.003;
	}
	else if(objType == "ALIEN")
	{
		*mAcceleration = 10.0;
		*mTurnRate = 0.008;
	}
	else if(objType == "DESTROYER")
	{
		*mAcceleration = 0.05;
		*mTurnRate = 0.0004;
	}
	else if(objType == "CARRIER")
	{
		*mAcceleration = 0.01;
		*mTurnRate = 0.0002;
	}
	else
	{
		*mAcceleration = 0.0;
		*mTurnRate = 0.0;
	}

	Physics* physics = new Physics(mPos, mVelocity, mScnNode, mSpeed, mHeading, mDesiredSpeed, mDesiredHeading, mTurnRate, mAcceleration);
	this->addAspect(physics);//physics at index 1

	mRotationSpeed = new float;
	Rotator* rotator = new Rotator(mScnNode, mRotationSpeed);
	this->addAspect(rotator);//rotator at index 2


}

Entity381::~Entity381()
{
	//do nothing
}

void Entity381::Tick(float dt)
{
	for (int i=0 ; i<aspects.size() ; i++)
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

Ogre::Vector3* Entity381::getVelocity()
{
	return mVelocity;
}

void Entity381::setVelocity(Ogre::Vector3 vel)
{
	*mVelocity = vel;
}

float* Entity381::getRotSpeed()
{
	return mRotationSpeed;
}

void Entity381::setRotSpeed(float rs)
{
	*mRotationSpeed = rs;
}

float Entity381::getSpeed()
{
	return *mDesiredSpeed;
}

float Entity381::getHeading()
{
	return *mDesiredHeading;
}

void Entity381::setDesiredHeading(float dHead)
{
	*mDesiredHeading = dHead;
}

void Entity381::setDesiredSpeed(float dSpd)
{
	*mDesiredSpeed = dSpd;
}

void Entity381::orientedMove()
{
	Physics* temp = (Physics*)this->getAspect(1);

	temp->orientedMove();
}
