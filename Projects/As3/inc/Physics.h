/*
 * Physics.h
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */

#ifndef INC_PHYSICS_H_
#define INC_PHYSICS_H_


#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <OgreVector3.h>
#include <OgreMath.h>
#include <string>

#include "Aspect.h"

class Physics : public Aspect
{
public:
	Physics();
	Physics(Ogre::Vector3*, Ogre::Vector3*, Ogre::SceneNode*, float*, float*, float*, float*, float*, float*);
	~Physics();

	Ogre::Vector3* getVelocity();
	void setVelocity(Ogre::Vector3);

	void orientedMove();

	void Tick(float);

private:
	Ogre::Vector3* mVelocity;
	Ogre::Vector3* mPos;
	Ogre::SceneNode* mScnNode;

	float* mSpeed;
	float* mHeading;
	float* mAcceleration;
	float* mTurnRate;
	float* mDesiredHeading;
	float* mDesiredSpeed;

};


#endif /* INC_PHYSICS_H_ */
