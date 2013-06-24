//
//  main.cpp
//  Queues
//
//  Created by Michael Kündig on 2/16/12.
//  Copyright 2012 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <queue>
#include "Car.h"

int main (int argc, const char * argv[])
{
    std::string userInput = "";
    std::queue<Car*> leftLane;
    std::queue<Car*> rightLane;
    
    bool redLightOn = true;
    
    int n;
    do {
        std::cout << "Input: \"car\", \"switch\" or \"stop\"." << std::endl;
        std::cin >> userInput;
        
        if (userInput == "car") {
            std::cout << "Input the car number: ";
            std::cin >> n;
            std::cout << std::endl;
            
            Car *c = new Car(n);
            if (redLightOn) {
                if (leftLane.size() > rightLane.size()) {
                    rightLane.push(c);
                    c->waitAtRedLight(2);
                } else {
                    leftLane.push(c);
                    c->waitAtRedLight(1);
                }
            } else {
                c->passCrossroads();
                delete c;
            }
        } else if (userInput == "switch") {
            redLightOn = false;
            while (!(leftLane.empty() && rightLane.empty())) {
                // to simulate simultaneous driving.
                if (!leftLane.empty()) {
                    leftLane.front()->passCrossroads();
                    leftLane.pop();
                }
                if (!rightLane.empty()) {
                    rightLane.front()->passCrossroads();
                    rightLane.pop();
                }
            }
        } else if (userInput != "stop") {
            std::cout << "Input not recognized! Try again." << std::endl;
        }
    } while (userInput != "stop");
    
    std::cout << "Program is quitting!";
    
    return 0;
}
