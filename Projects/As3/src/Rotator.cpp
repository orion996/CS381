/*
 * Rotator.cpp
 *
 *  Created on: Feb 23, 2019
 *      Author: orion996
 */
#include "Rotator.h"

Rotator::Rotator(Ogre::SceneNode* node)
{
	mScnNode = node;
	rotationSpeed = 0.0;
}

Rotator::~Rotator()
{

}

float Rotator::getRotationSpeed()
{
	return rotationSpeed;
}

void Rotator::setRotationSpeed(float rs)
{
	rotationSpeed = rs;
}

void Rotator::Tick(float dt)
{
	mScnNode->yaw(Ogre::Degree(rotationSpeed) * dt);
}



