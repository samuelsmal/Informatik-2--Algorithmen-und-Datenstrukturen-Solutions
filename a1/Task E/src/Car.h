/*
 *  Car.h
 *  task_3
 *
 *  Created by Matthias Thöny on 2/3/12.
 *  Copyright 2012 __MyCompanyName__. All rights reserved.
 *
 */

#ifndef CAR_H
#define CAR_H

#include <vector>
#include "Vehicle.h"
#include "Wheel.h"

class Car
{
public:
	Car(bool);
	~Car();
	
	int getNumberOfSeats();
    bool hasSummerWheels();
    float getLength();
	
private:
	Wheel* wheels[4];
	int number_of_seats;
};

#endif
