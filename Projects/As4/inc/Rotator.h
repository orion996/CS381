/*
 * Rotator.h
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */

#ifndef INC_ROTATOR_H_
#define INC_ROTATOR_H_

#include <OgreVector3.h>
#include <OgreSceneNode.h>

#include "Aspect.h"

class Rotator : public Aspect
{
public:
	Rotator(Ogre::SceneNode*, float*);
	Rotator();
	~Rotator();

	float* getRotationSpeed();
	void setRotationSpeed(float);

	void Tick(float);

private:
	float* mRotationSpeed;
	Ogre::SceneNode* mScnNode;
};

#endif /* INC_ROTATOR_H_ */
