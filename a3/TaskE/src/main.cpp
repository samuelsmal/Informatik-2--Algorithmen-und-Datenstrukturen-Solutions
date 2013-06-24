//
//  main.cpp
//  Busdriver
//
//  Created by Fabian Hofstetter on 23.02.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//

#include <iostream>
#include <map>
#include <cstdlib>
#include <string>
#include "Passenger.h"
#define SIZEOFBUS 30
#define NUMBEROFSTATIONS 8
#define TIMEBETWEENSTATIONS 1

#define my_delete(x) {delete x; x = NULL;}

std::map<std::string, Passenger*> onTheBus;

void init();
void wait(int seconds);
void print();
void letPassengersOut();
int getNumberOfPassengers();

int startStation = 1;
int currentStation;

std::string seats[SIZEOFBUS] = {
		"Row 1,  seat A", "Row 1,  seat B", "Row 1,  seat C",
		"Row 2,  seat A", "Row 2,  seat B", "Row 2,  seat C",
		"Row 3,  seat A", "Row 3,  seat B", "Row 3,  seat C",
		"Row 4,  seat A", "Row 4,  seat B", "Row 4,  seat C",
		"Row 5,  seat A", "Row 5,  seat B", "Row 5,  seat C",
		"Row 6,  seat A", "Row 6,  seat B", "Row 6,  seat C",
		"Row 7,  seat A", "Row 7,  seat B", "Row 7,  seat C",
		"Row 8,  seat A", "Row 8,  seat B", "Row 8,  seat C",
		"Row 9,  seat A", "Row 9,  seat B", "Row 9,  seat C",
		"Row 10, seat A", "Row 10, seat B", "Row 10, seat C"
};

int main (int argc, const char * argv[])
{

    init();
    
    currentStation = startStation;
    
    for(int i=0; i<NUMBEROFSTATIONS; i++){
        letPassengersOut();
        
        print();
        currentStation = (currentStation + 1);
        wait(TIMEBETWEENSTATIONS);
    }
    
    
    return 0;
}

void init(){    
    for(int i=0; i < SIZEOFBUS; i++){
        int enterStation = (rand() % NUMBEROFSTATIONS) + 1;
        int leaveStation = (rand() % NUMBEROFSTATIONS) + 1;
        
        onTheBus.insert(std::pair<std::string, Passenger*>(seats[i], new Passenger(enterStation, leaveStation)));
    }
}

void wait(int seconds){
    sleep(seconds);
}

void letPassengersOut(){
    std::map<std::string, Passenger*>::iterator itr;
    for (itr = onTheBus.begin(); itr != onTheBus.end(); ++itr) {
        if (itr->second->getLeaveStation() == currentStation) {
            my_delete(itr->second);
            onTheBus.erase(itr);
        }
        
    }
}

void print(){
    if (getNumberOfPassengers() <= 0) {
        std::cout << "The bus is empty!\n";
        return;
    }
    
    std::cout << "Arrived at station Nr." << currentStation << "\n";
    std::cout << "Still occupied are:\tEntered at\twill leave at\n";
    std::map<std::string, Passenger*>::const_iterator itr;
    for (itr = onTheBus.begin(); itr != onTheBus.end(); ++itr) {
        std::cout << itr->first << "\t\t\t" << itr->second->getEnterStation() << "\t\t\t" << itr->second->getLeaveStation() << "\n";
    }
}

int getNumberOfPassengers(){
    return onTheBus.size();
}

