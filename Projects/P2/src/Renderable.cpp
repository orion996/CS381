/*
 * Renderable.cpp
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */
#include "Renderable.h"

Renderable::Renderable()
{
	//do nothing
}

Renderable::Renderable(Ogre::Vector3* pos, Ogre::SceneManager* mgr, std::string obj, std::string name)
{
	mPos = pos;
	mName = name;
	mScnMgr = mgr;

	if(obj == "SPHERE")//sphere
	{
		mEntity = mScnMgr->createEntity("sphere.mesh");
	}
	else if(obj == "CUBE")
	{
		mEntity = mScnMgr->createEntity("cube.mesh");
	}
	else if(obj == "BANSHEE")
	{

	}

	mScnNode = mScnMgr->getRootSceneNode()->createChildSceneNode(mName);
	mScnNode->attachObject(mEntity);
	mScnNode->setPosition(*mPos);
}

Renderable::~Renderable()
{
	//do nothing
}

void Renderable::Tick(float dt)
{
	mScnNode->setPosition(*mPos);
}

Ogre::SceneNode* Renderable::getSceneNode()
{
	return mScnNode;
}

void Renderable::showBox(bool show)
{
	mScnNode->showBoundingBox(show);
}

