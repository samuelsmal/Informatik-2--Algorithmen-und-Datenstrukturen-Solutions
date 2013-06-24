//
//  stack_ab.cpp
//  stack_arraybased
//
//  Created by Loc Nguyen on 16.02.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//

#include <iostream>
#include "stack_ab.h"

Stack_ab::Stack_ab()
{
    index = -1;
    of = new OverFlow;
    uf = new UnderFlow;
}

Stack_ab::~Stack_ab()
{
    delete of;
    delete uf;
}


int Stack_ab::size()
{
    
    return (index > -1) ? index + 1 : 0;
}


void Stack_ab::push(std::string newelement)
{
    if (index < StackMax - 1) {
        data[++index] = newelement;
    } else {
        of->overflowoutput();
    }
    
}


std::string Stack_ab::pop()
{
    if (index >= 0) {
        return data[index--];
    } else {
        uf->underflowoutput();
        return "Error no element to pop";
    }
}

std::string Stack_ab::top()
{
    if (index > -1) {
        return data[index];
    } else {
        uf->underflowoutput();
        return "Nobody";
    }
    
}

bool Stack_ab::empty()
{
    return index == -1;
}


