/*
 *
 *  Created by Matthias Thöny on 2/3/12.
 *  Updated by Rafael Ballester on 09.01.13.
 *  Copyright (c) 2013 Uni Zürich. All rights reserved.
 *
 */

#ifndef COLORTABLE_H
#define COLORTABLE_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

struct Color
{
	std::string name;
    int r, g, b;
};

class ColorTable
{
public:
	ColorTable();
    
    void readColorTable(std::string filename);
    bool getColor(std::string name, Color *foundColor);
    
//private:
    Color colors[8];
};

#endif
