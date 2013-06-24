//
//  house.h
//  House_Buying
//
//  Created by Fabian Hofstetter on 07.02.12.
//  Updated by Rafael Ballester on 09.01.13.
//  Copyright 2013 Universität Zürich. All rights reserved.
//

#include <string>

#ifndef Test_house_h
#define Test_house_h


class House{
public:
    House(int rooms_, int squareMeters_, double price_, std::string street_, std::string roadNumber_, std::string postalCode_, std::string city_);
    /* TODO 5b)
     *
     * declare a destructor
     *
     */
    int getRooms();
    int getSquareMeters();
    float getPrice();
    std::string getAddress();
    
private:
    std::string street;
    std::string roadNumber;
    std::string postalCode;
    std::string city;
    int rooms;
    int squareMeters;
    double price;
    
};


#endif
