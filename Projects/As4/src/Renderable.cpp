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
		mScnNode = mScnMgr->getRootSceneNode()->createChildSceneNode(mName);
		mScnNode->attachObject(mEntity);
		mScnNode->setPosition(*mPos);
	}
	else if(obj == "SAILBOAT")
	{
		mEntity = mScnMgr->createEntity("../assets/sailboat.mesh");
		mEntity->setMaterialName("Wood_Lumber_ButtJoined");
		mScnNode = mScnMgr->getRootSceneNode()->createChildSceneNode(mName);
		mScnNode->attachObject(mEntity);
		mScnNode->setPosition(*mPos);
//		mScnNode->yaw(Ogre::Degree(-90));
	}
	else if(obj == "CIG")
	{
		mEntity = mScnMgr->createEntity("../assets/cigarette.mesh");
		mEntity->setMaterialName("SOLID/TEX/ecslHorizontal.bmp");
		mScnNode = mScnMgr->getRootSceneNode()->createChildSceneNode(mName);
		mScnNode->attachObject(mEntity);
		mScnNode->setPosition(*mPos);
//		mScnNode->yaw(Ogre::Degree(-90));
	}
	else if(obj == "ALIEN")
	{
		mEntity = mScnMgr->createEntity("../assets/alienship.mesh");
		mEntity->setMaterialName("al-1");
		mScnNode = mScnMgr->getRootSceneNode()->createChildSceneNode(mName);
		mScnNode->attachObject(mEntity);
		mScnNode->setPosition(*mPos);
//		mScnNode->yaw(Ogre::Degree(90));
	}
	else if(obj == "DESTROYER")
	{
		mEntity = mScnMgr->createEntity("../assets/ddg51.mesh");
		mEntity->setMaterialName("C000007");
		mScnNode = mScnMgr->getRootSceneNode()->createChildSceneNode(mName);
		mScnNode->attachObject(mEntity);
		mScnNode->setPosition(*mPos);
//		mScnNode->yaw(Ogre::Degree(90));
	}
	else if(obj == "CARRIER")
	{
		mEntity = mScnMgr->createEntity("../assets/cvn68.mesh");
		mEntity->setMaterialName("DECK_WHITE/SOLID/TEX/ecslDark.bmp/VertCol");
		mScnNode = mScnMgr->getRootSceneNode()->createChildSceneNode(mName);
		mScnNode->attachObject(mEntity);
		mScnNode->setPosition(*mPos);
//		mScnNode->yaw(Ogre::Degree(90));
	}
	else
	{
		mEntity = mScnMgr->createEntity("cube.mesh");
		mScnNode = mScnMgr->getRootSceneNode()->createChildSceneNode(mName);
		mScnNode->attachObject(mEntity);
		mScnNode->setPosition(*mPos);
	}



}

Renderable::~Renderable()
{
	//do nothing
}

void Renderable::Tick(float dt)
{
	//mScnNode->setPosition(*mPos);
	//mScnNode->translate(*mPos * dt, Ogre::Node::TS_LOCAL);
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
