/*
 * Physics.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */
#include "Physics.h"

Physics::Physics()
{
	//do nothing
}

Physics::Physics(Ogre::Vector3* pos, Ogre::Vector3* vel, Ogre::SceneNode* nd, float* spd, float* head, float* dSpd, float* dHead, float* turnRate, float* acc)
{
	mVelocity = vel;
	mPos = pos;
	mScnNode = nd;

	mSpeed = spd;
	mHeading = head;
	mDesiredSpeed = dSpd;
	mDesiredHeading = dHead;
	mTurnRate = turnRate;
	mAcceleration = acc;
}

Physics::~Physics()
{
	//do nothing
}

void Physics::setVelocity(Ogre::Vector3 velocity)
{
	mVelocity->x = velocity.x;
	mVelocity->y = velocity.y;
	mVelocity->z = velocity.z;
}

Ogre::Vector3* Physics::getVelocity()
{
	return mVelocity;
}

void Physics::Tick(float dt)
{
	mPos->x = mPos->x + (mVelocity->x * dt);
	mPos->y = mPos->y + (mVelocity->y * dt);
	mPos->z = mPos->z + (mVelocity->z * dt);
}

void Physics::orientedMove()
{
	//set speed
	if(*mSpeed > *mDesiredSpeed)
	{
		*mSpeed -= *mAcceleration;
	}
	if(*mSpeed < *mDesiredSpeed)
	{
		*mSpeed += *mAcceleration;
	}

//	mHeading = (mHeading % 360);
//	mDesiredHeading = (mDesiredHeading % 360);

	//compensate heading to 360 degrees
	if(*mHeading >= 360)
		*mHeading -= 360;

	if(*mDesiredHeading >= 360)
		*mDesiredHeading -= 360;

	if(*mHeading <= -360)
		*mHeading += 360;

	if(*mDesiredHeading <= -360)
		*mDesiredHeading += 360;

	//set heading
	if(*mHeading > *mDesiredHeading && *mSpeed != 0)
	{
		*mHeading -= *mTurnRate;
	}
	else if(*mHeading < *mDesiredHeading && *mSpeed != 0)
	{
		*mHeading += *mTurnRate;
	}


	//set velocity
	*mVelocity = Ogre::Vector3(
					(*mSpeed * (Ogre::Math::Cos(*mHeading))), //Vx = s*cos(h)
					0,
					(*mSpeed * (Ogre::Math::Sin(*mHeading))));//Vy = s*sin(h)


	//set direction
	Ogre::Vector3 src = mScnNode->getOrientation() * Ogre::Vector3::UNIT_X;
	Ogre::Quaternion quat = src.getRotationTo(*mVelocity);
	mScnNode->rotate(quat);
}
