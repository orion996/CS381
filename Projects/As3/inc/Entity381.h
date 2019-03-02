/*
 * Entity381.h
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */

#ifndef INC_ENTITY381_H_
#define INC_ENTITY381_H_

#include "Aspect.h"
#include "Renderable.h"
#include "Physics.h"
#include "Rotator.h"

#include <OgreVector3.h>
#include <OgreSceneManager.h>
#include <OgreNode.h>
#include <OgreMath.h>
#include <vector>

class Entity381
{
public:
	Entity381();
	Entity381(Ogre::SceneManager*, std::string, std::string, Ogre::Vector3);
	~Entity381();

	void Tick(float dt);

	void setPosition(Ogre::Vector3);
	void addAspect(Aspect*);
	Aspect* getAspect(int);
	Ogre::Vector3* getVelocity();
	void setVelocity(Ogre::Vector3);
	void setRotSpeed(float);
	float* getRotSpeed();

	//as3 functions
	void orientedMove();
	float getSpeed();
	float getHeading();
	void setDesiredSpeed(float);
	void setDesiredHeading(float);

	Ogre::SceneNode* mScnNode;
	Ogre::Vector3* mPos;
	Ogre::SceneManager* mScnMgr;
	bool isSelected = false;
	std::string mName;
	Ogre::Vector3* mVelocity;
	float* mRotationSpeed;

	//as3 variables
	float* mSpeed;
	float* mHeading;
	float* mAcceleration;
	float* mTurnRate;
	float* mDesiredHeading;
	float* mDesiredSpeed;

private:
	std::vector<Aspect*> aspects;
};



#endif /* INC_ENTITY381_H_ */
