//
//  EmptyContainerException.cpp
//  TaskC
//
//  Created by Samuel von Bausznern on 18.04.13.
//
//

#include "EmptyContainerException.h"

EmptyContainerException::EmptyContainerException()
{
}

std::string EmptyContainerException::getMessage()
{
    return "Container is empty!\n";
}