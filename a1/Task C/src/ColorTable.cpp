/*
 *
 *  Created by Matthias Thöny.
 *  Updated by Rafael Ballester on 09.01.13.
 *  Copyright (c) 2013 Uni Zürich. All rights reserved.
 *
 */

#include "ColorTable.h"

using namespace std;

ColorTable::ColorTable()
{
	
}

/*
 * TODO 1: Implement reading a specific colortable given by a filename and put the color values in the color structure.
 */
void ColorTable::readColorTable(std::string filename)
{
    
    ifstream colorFile(filename);
    
    string line;
    
    string name;
    int r, g, b;
    
    /*
    int linecount = 0;
    while (colorFile >> name >> r >> g >> b) {
        cout << name + "\n";
        cout << r << endl;
        colors[linecount].name = name;
        colors[linecount].r = r;
        colors[linecount].g = g;
        colors[linecount].b = b;
        linecount++;
    }*/
    
    int linecount = 0;
    while (getline(colorFile, line)) {
        cout << linecount << ": " << line << endl;
    }
    
    /*
    for (int i = 0; getline(colorFile, line); i++) {
        istringstream iss(line);
        if (!(iss >> name >> r >> g >> b)) {
            break;
        }
        colors[i].name = name;
        colors[i].r = r;
        colors[i].g = g;
        colors[i].b = b;
    }*/
    
}

/*
 * TODO 2: look for a color
 */
bool ColorTable::getColor(std::string name, Color *foundColor) {

}
