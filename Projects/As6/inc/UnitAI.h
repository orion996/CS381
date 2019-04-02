/*
 * UnitAI.h
 *
 *  Created on: Apr 1, 2019
 *      Author: orion996
 */

#ifndef INC_UNITAI_H_
#define INC_UNITAI_H_

#include <list>
#include <string>
#include <OgreVector3.h>
#include <Aspect.h>
//#include <Entity381.h>
#include <OgreNode.h>

//class Entity381;


struct Command
{
	std::string type;
	Ogre::Vector3 point;
	bool isDone;
	Entity381* target;

};

class UnitAI : Aspect
{
public:
	std::list<Command*> commands;

	UnitAI(Entity381* ent);
	~UnitAI();

	void Tick(float dt);
	void SetCommand(std::string, Ogre::Vector3, Entity381*);
	void AddCommand(std::string, Ogre::Vector3, Entity381*);

	void clearCommands();
	void deleteCurrentCommand();
};



#endif /* INC_UNITAI_H_ */