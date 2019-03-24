/*
 * Entity381.cpp
 *
 *  Created on: Feb 7, 2018
 *      Author: sushil
 */

#include <GfxMgr.h>

#include<Entity381.h>
#include<Physics2D.h>
#include<Physics3D.h>

std::string IntToString(int x){
	char tmp[10000];
	sprintf(tmp, "%i", x);
	return std::string(tmp);
}

Entity381::Entity381(Engine *engine, std::string meshfname, Ogre::Vector3 pos, int ident){

	this->engine = engine;

	Renderable * renderable = new Renderable(this);
	aspects.push_back((Aspect*)renderable);

	meshfilename = meshfname;
	position = pos;
	velocity = Ogre::Vector3(0, 0, 0);
	identity = ident;
	isSelected = false;

	name = meshfname + IntToString(identity);

	ogreEntity = engine->gfxMgr->mSceneMgr->createEntity(meshfilename);
	sceneNode = engine->gfxMgr->mSceneMgr->getRootSceneNode()->createChildSceneNode(pos);
	sceneNode->attachObject(ogreEntity);

//	Physics2D* phx2d = new Physics2D(this);
//	aspects.push_back((Aspect*) phx2d);

	this->acceleration = 0;
	this->desiredHeading = this->heading = 0;
	this->turnRate = 0;
	this->desiredSpeed = this->speed = 0;
	this->minSpeed = this->maxSpeed = 0;

	this->climbRate = 0;
	this->altitude = this->desiredAltitude = 0;

}

Entity381::~Entity381(){

}

void Entity381::Tick(float dt){
	for(unsigned int i = 0; i < aspects.size(); i++){
		aspects[i]->Tick(dt);
	}
}

//-------------------------------------------------------------------------------------------------------------------------------
DDG51::DDG51(Engine *engine, std::string meshfname, Ogre::Vector3 pos, int ident):
		Entity381(engine, meshfname, pos, ident){
	this->minSpeed = 0;
	this->maxSpeed = 16.0f;//meters per second...
	this->acceleration = 5.0f; // fast
	this->turnRate = 20.0f; //4 degrees per second
	std::cout << "Created: " << this->name << std::endl;
	Physics2D* phx2d = new Physics2D(this);
		aspects.push_back((Aspect*) phx2d);
}

DDG51::~DDG51(){

}

//-------------------------------------------------------------------------------------------------------------------------------
Carrier::Carrier(Engine *engine, std::string meshfname, Ogre::Vector3 pos, int ident):
		Entity381(engine, meshfname, pos, ident){
	this->minSpeed = 0;
	this->maxSpeed = 20.0f;//meters per second...
	this->acceleration = 1.0f; // slow
	this->turnRate = 10.0f; //2 degrees per second
	Physics2D* phx2d = new Physics2D(this);
		aspects.push_back((Aspect*) phx2d);
}

Carrier::~Carrier(){

}
//-------------------------------------------------------------------------------------------------------------------------------

SpeedBoat::SpeedBoat(Engine *engine, std::string meshfname, Ogre::Vector3 pos, int ident):
		Entity381(engine, meshfname, pos, ident){
	this->minSpeed = 0;
	this->maxSpeed = 30.0f;//meters per second...
	this->acceleration = 5.0f; // slow
	this->turnRate = 30.0f; //2 degrees per second
	Physics2D* phx2d = new Physics2D(this);
		aspects.push_back((Aspect*) phx2d);
}

SpeedBoat::~SpeedBoat(){

}
//-------------------------------------------------------------------------------------------------------------------------------

Frigate::Frigate(Engine *engine, std::string meshfname, Ogre::Vector3 pos, int ident):
		Entity381(engine, meshfname, pos, ident){
	this->minSpeed = 0;
	this->maxSpeed = 15.0f;//meters per second...
	this->acceleration = 5.0f; // slow
	this->turnRate = 20.0f; //2 degrees per second
	Physics2D* phx2d = new Physics2D(this);
		aspects.push_back((Aspect*) phx2d);
}

Frigate::~Frigate(){

}

//-------------------------------------------------------------------------------------------------------------------------------
Alien::Alien(Engine *engine, std::string meshfname, Ogre::Vector3 pos, int ident):
		Entity381(engine, meshfname, pos, ident){
	this->minSpeed = 0;
	this->maxSpeed = 50.0f;//meters per second...
	this->acceleration = 10.0f; // slow
	this->turnRate = 40.0f; //2 degrees per second
	this->climbRate = 40.0f;
	Physics3D* phx3d = new Physics3D(this);
		aspects.push_back((Aspect*) phx3d);
}

Alien::~Alien(){

}
//-------------------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------------------------------------------------------------------------------------
Banshee::Banshee(Engine *engine, std::string meshfname, Ogre::Vector3 pos, int ident):
		Entity381(engine, meshfname, pos, ident){
	this->minSpeed = 0;
	this->maxSpeed = 50.0f;//meters per second...
	this->acceleration = 10.0f; // slow
	this->turnRate = 40.0f; //2 degrees per second
	this->climbRate = 40.0f;
	Physics3D* phx3d = new Physics3D(this);
		aspects.push_back((Aspect*) phx3d);
}

Banshee::~Banshee(){

}
//--------------------------------------------------------------------------------------

