//
//  main.cpp
//  House_Buying
//
//  Created by Fabian Hofstetter on 07.02.12.
//  Adapted and updated by Rafael Ballester on 09.01.13.
//  Copyright 2013 Universität Zürich. All rights reserved.
//

#include <iostream>
#include <cmath>
#include "House.h"

struct Desires{
    int rooms;
    int squareMeters;
    double price;
};

bool checkRooms(House* myHouse, Desires myDesire);
bool checkSquareMeters(House* myHouse, Desires myDesire);
void printHouseDescription(House* myHouse);
bool checkPrice(House* myHouse, Desires myDesire);

int main (int argc, const char * argv[])
{

    House dreamHouse(5, 1200, 25000.55, "Musterstrasse", "4", "8050", "Zürich");
    printHouseDescription(&dreamHouse);

	/* TODO 5c)
	 *
	 * declare a Desires instance called "myDesire" in the heap. Remember
	 * to delete it later, when it is no longer needed
	 *
	 * write your implementation here
	 */
    myDesire->rooms = 2;
    myDesire->squareMeters = 1000;
    myDesire->price = 750000.00;
    
    if(
    checkRooms(&dreamHouse, *myDesire) &&
       checkPrice(&dreamHouse, *myDesire)){
        printHouseDescription(&dreamHouse);
    }

    return 0;
    
}

bool checkRooms(House* myHouse, Desires myDesire){
    /* TODO 1)
     *
     * this method should check, if there are enough rooms in the house
     *
     * write your implementation here
     */
}

bool checkPrice(House* myHouse, Desires myDesire){
    /* TODO 2)
     *
     * this method should check, if the price isn't too high
     *
     * write your implementation here
     */
}

float getPerimeter(House* myHouse){
    /* TODO 4)
     *
     * this method should calculate the perimeter of the house,
     * supposing it has a square shape
     *
     * write your implementation here
     */
}

void printHouseDescription(House* myHouse){
    /* TODO 6)
     *
     * this method should print out a short description about the given house
     *
     * write your implementation here
     */
}
