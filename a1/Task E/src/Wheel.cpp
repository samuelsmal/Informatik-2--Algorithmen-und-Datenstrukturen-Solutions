#include <iostream>
#include "Wheel.h"

Wheel::Wheel(bool isSummerWheel)
{

}

Wheel::~Wheel() {

}

float Wheel::size()
{
	return size_in_inches;
}

bool Wheel::isSummerWheel()
{
	return model;
}
