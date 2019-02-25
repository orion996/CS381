/*
 * Aspect.h
 *
 *  Created on: Feb 22, 2019
 *      Author: orion996
 */

#ifndef INC_ASPECT_H_
#define INC_ASPECT_H_

class Aspect
{
public:
	Aspect();
	virtual ~Aspect();

	virtual void Tick(float dt);
};



#endif /* INC_ASPECT_H_ */
