/*
 *  Car.h
 *  task_3
 *
 *  Created by Matthias Thöny on 2/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef WHEEL_H
#define WHEEL_H

#include "Wheel.h"

class Wheel
{
public:
	Wheel(bool);
	~Wheel();
	
	float size();
    bool isSummerWheel();
	
private:

	bool model;
	float size_in_inches;
	
};

#endif
