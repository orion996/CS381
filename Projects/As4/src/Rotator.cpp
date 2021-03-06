/*
 * Rotator.cpp
 *
 *  Created on: Feb 23, 2019
 *      Author: orion996
 */
#include "Rotator.h"

Rotator::Rotator(Ogre::SceneNode* node, float *rs)
{
	mScnNode = node;
	mRotationSpeed = rs;
	*mRotationSpeed = 0.0;

}

Rotator::~Rotator()
{

}

float* Rotator::getRotationSpeed()
{
	return mRotationSpeed;
}

void Rotator::setRotationSpeed(float rs)
{
	*mRotationSpeed = rs;
}

void Rotator::Tick(float dt)
{
	mScnNode->yaw(Ogre::Degree(*mRotationSpeed) * dt);

	//std::cout << "********* " << *mRotationSpeed << " ************" << std::endl;
}



