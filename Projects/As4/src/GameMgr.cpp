/*
 * GameMgr.cpp
 *
 *  Created on: Mar 8, 2019
 *      Author: orion996
 */

#include "GameMgr.h"

GameMgr::GameMgr(Ogre::SceneManager* smgr, Engine* eng)
{
	mSceneMgr = smgr;
	mEngine = eng;
}

GameMgr::~GameMgr()
{

}

bool GameMgr::Init()
{
	mSceneMgr->setAmbientLight(Ogre::ColourValue(0.5,0.5,0.5));
	mSceneMgr->setShadowTechnique(Ogre::SHADOWTYPE_STENCIL_MODULATIVE);

	this->makeEntities();
	this->makeLight();
	this->makeSky();
	this->makeGround(-1.0);

	return true;
}

void GameMgr::makeSky()
{
	mSceneMgr->setSkyBox(true, "Examples/StormySkyBox");
}

void GameMgr::makeGround(float surfaceHeight)
{
	//create the plane
		Ogre::Plane plane(Ogre::Vector3::UNIT_Y, 0);
		Ogre::MeshManager::getSingleton().createPlane(
				"ground", Ogre::ResourceGroupManager::DEFAULT_RESOURCE_GROUP_NAME, //region name
				plane, //plane object
				10000, 10000, 20, 20, //dimensions?
				true, //toggle normal?
				1, 5, 5, //uv coordinate stuff
				Ogre::Vector3::UNIT_Z //normal vector
		);

		//attach ground to the scene
		Ogre::SceneNode* floorNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
		Ogre::Entity* floorEnt = mSceneMgr->createEntity("ground");
		floorNode->setPosition(Ogre::Vector3(0, surfaceHeight, 0));
		floorNode->attachObject(floorEnt);
		floorEnt->setCastShadows(false);
		floorEnt->setMaterialName("Ocean2_HLSL_GLSL");
//		floorEnt->setMaterialName("Examples/Rockwall");
}

void GameMgr::makeLight()
{
	Ogre::Light* light = mSceneMgr->createLight("MainLight");
	Ogre::SceneNode* lightNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
	lightNode->attachObject(light);
	lightNode->setDirection(-1, -1, 0);
	light->setPosition(100,340,220);
}

void GameMgr::makeEntities()
{
//	Ogre::Entity* ogreEntity = mSceneMgr->createEntity("ogrehead.mesh");
//	Ogre::SceneNode* ogreNode = mSceneMgr->getRootSceneNode()->createChildSceneNode();
//	ogreNode->attachObject(ogreEntity);

	mEngine->getEntityMgr()->createEntity("SAILBOAT", "SailBoat", Ogre::Vector3(0,0,0));
	mEngine->getEntityMgr()->createEntity("CIG", "CigBoat", Ogre::Vector3(0, 0, 50));
	mEngine->getEntityMgr()->createEntity("ALIEN", "AlienShip", Ogre::Vector3(0, 0, 100));
	mEngine->getEntityMgr()->createEntity("DESTROYER", "Ddg", Ogre::Vector3(0,0,150));
	mEngine->getEntityMgr()->createEntity("CARRIER", "Cvn", Ogre::Vector3(0,0,300));
}
