/*
 * UnitAI.cpp
 *
 *  Created on: Apr 1, 2019
 *      Author: orion996
 */

#include <UnitAI.h>
#include <Entity381.h>


UnitAI::UnitAI(Entity381* ent) : Aspect(ent)
{

}

UnitAI::~UnitAI()
{

}

void UnitAI::AddCommand(std::string type, Ogre::Vector3 point, Entity381* tgt)
{
	Command* tempCom = new Command();
	tempCom->type = type;
	tempCom->point = point;
	tempCom->isDone = false;
	tempCom->target = tgt;

	commands.push_back(tempCom);
}

void UnitAI::SetCommand(std::string type, Ogre::Vector3 point, Entity381* tgt)
{
	Command* tempCom = new Command();
	tempCom->type = type;
	tempCom->point = point;
	tempCom->isDone = false;
	tempCom->target = tgt;

	commands.clear();
	commands.push_back(tempCom);

}

void UnitAI::Tick(float dt)
{
	//seg fault if the list is empty, so return instead
	if(commands.empty())
		return;

	if(commands.front()->type == "MOVETO")
	{
		Ogre::Vector3 pos = entity->position;
		Ogre::Vector3 direction = commands.front()->point - pos;

		//check if point equals the current position
		if(pos == commands.front()->point)//if yes, stop moving and pop the command
		{
			entity->desiredSpeed = entity->speed = 0;
			commands.pop_front();
		}
		else//if no, rotate entity towards the point and max speed
		{
			entity->desiredHeading = (Ogre::Math::ATan2(direction.z, direction.x)).valueDegrees();
			entity->desiredSpeed = entity->maxSpeed;
		}
	}
	else if(commands.front()->type == "INTERCEPT")
	{
		//update the target position
		commands.front()->point = commands.front()->target->position;

		Ogre::Vector3 pos = entity->position;
		Ogre::Vector3 direction = commands.front()->point - pos;

		//check if point equals the current position
		if(pos == commands.front()->point)//if yes, stop moving and pop the command
		{
			entity->desiredSpeed = entity->speed = 0;
			commands.pop_front();
		}
		else//if no, rotate entity towards the point and max speed
		{
			entity->desiredHeading = (Ogre::Math::ATan2(direction.z, direction.x)).valueDegrees();
			entity->desiredSpeed = entity->maxSpeed;
		}
	}
	else
	{
		commands.pop_front();
	}
}


void UnitAI::clearCommands()
{
	commands.clear();
}
