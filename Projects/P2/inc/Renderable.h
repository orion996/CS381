/*
 * Renderable.h
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */

#ifndef INC_RENDERABLE_H_
#define INC_RENDERABLE_H_

#include <OgreSceneNode.h>
#include <OgreSceneManager.h>
#include <OgreEntity.h>
#include <OgreNode.h>
#include <string>

#include "Aspect.h"

class Renderable : public Aspect
{
public:
	Renderable();
	Renderable(Ogre::Vector3*, Ogre::SceneManager*, std::string, std::string);
	~Renderable();

	virtual void Tick(float dt);

	Ogre::SceneNode* getSceneNode();

	void showBox(bool);

private:
	Ogre::Entity* mEntity;
	Ogre::SceneNode* mScnNode;
	Ogre::Vector3* mPos;
	Ogre::SceneManager* mScnMgr;
	std::string mName;

};



#endif /* INC_RENDERABLE_H_ */
