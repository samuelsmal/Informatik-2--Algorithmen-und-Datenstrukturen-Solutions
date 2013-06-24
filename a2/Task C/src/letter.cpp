//
//  letter.cpp
//  Mail
//
//  Created by Fabian Hofstetter on 09.02.12.
//  Copyright 2012 Universität Zürich. All rights reserved.
//

#include <iostream>
#include "letter.hpp"

letter::letter(int priority_, std::string tray_, std::string sender_) : priority(priority_), tray(tray_), sender(sender_)
{
    priority = priority_;
    tray = tray_;
    sender = sender_;
    
}

int letter::getPriority(){
    return priority;
}


std::string letter::getTray(){
    return tray;
}


std::string letter::getSender(){
    return sender;
}