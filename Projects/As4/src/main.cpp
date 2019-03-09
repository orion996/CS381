/*
 * main.cpp
 *
 *  Created on: Mar 7, 2019
 *      Author: orion996
 */

#include "Engine.h"

int main(int argc, char *argv[])
{
	Engine *engine = new Engine();
	engine->Init();
	engine->Run();
//	engine->Cleanup();
	return 0;}
