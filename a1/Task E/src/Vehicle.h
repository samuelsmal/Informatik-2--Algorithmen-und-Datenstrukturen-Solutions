/*
 *  Car.h
 *  task_3
 *
 *  Created by Matthias Thöny on 2/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */
#ifndef VEHICLE_H
#define VEHICLE_H

#include "Vehicle.h"

class Vehicle
{
public:	
    Vehicle();
	
	float getLength();
	float getMaximumVelocity();
    
protected:

	float length;

private:
	float maximumVelocity;
    
};

#endif
