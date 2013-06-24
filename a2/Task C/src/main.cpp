//
//  main.cpp
//  Mail
//
//  Created by Fabian Hofstetter on 09.02.12.
//  Updated by Rafael Ballester on 15.01.13.
//  Copyright 2013 Universität Zürich. All rights reserved.
//

#include <iostream>
#include <stack>

#include "letter.hpp"

void printTray(std::stack<letter*> tray);

void init();
void printTrays();
void cleanUp();
std::stack<letter*> orderByPriority(std::stack<letter*> tray);

std::stack<letter*> tray_work;
std::stack<letter*> tray_family;
std::stack<letter*> tray_hobby;

int main (int argc, const char * argv[])
{

    init();
    
    printTrays();
    
    cleanUp();
    
    printTrays();
    
    std::cout << "Ordering trays:" << std::endl;
    
    tray_work = orderByPriority(tray_work);
    tray_family = orderByPriority(tray_family);
    tray_hobby = orderByPriority(tray_hobby);
    
    printTrays();
    
    return 0;
}

void init(){
    
    letter* letter1 = new letter(5, "work", "John");
    letter* letter2 = new letter(3, "family", "Jack");
    letter* letter3 = new letter(1, "work", "Hugo");
    letter* letter4 = new letter(9, "hobby", "Lisa");
    letter* letter5 = new letter(4, "family", "Lena");
    letter* letter6 = new letter(0, "work", "Madden");
    letter* letter7 = new letter(8, "hobby", "Jules");
    letter* letter8 = new letter(4, "hobby", "Rachel");
    letter* letter9 = new letter(0, "family", "Sam");
    letter* letter10 = new letter(7, "work", "Lio");

    tray_work.push(letter1);
    tray_work.push(letter2);
    tray_work.push(letter3);
    
    tray_family.push(letter4);
    tray_family.push(letter5);
    tray_family.push(letter6);
    
    tray_hobby.push(letter7);
    tray_hobby.push(letter8);
    tray_hobby.push(letter9);
    tray_hobby.push(letter10);

}

void printTray(std::stack<letter*> tray) {
    std::cout << "  Priority || " << "Tray || " << "Sender" << std::endl;
    
    while (! tray.empty()) {
        letter *te = tray.top();
        std::cout << "  " << te->getPriority() << "\t\t" << te->getTray() << "\t\t" << te->getSender() << std::endl;
        tray.pop();
    }
}

void printTrays(){
    std::cout << "Work tray:" << std::endl;
    printTray(tray_work);
    std::cout << "Hobby tray:" << std::endl;
    printTray(tray_hobby);
    std::cout << "Family tray:" << std::endl;
    printTray(tray_family);
}


void cleanUp(){
    /* TODO 2)
     *
     * this method should clean up the trays. This means every letter should be in the correct tray in which it belongs to.
     *
     * write your implementation here
     */
    
    std::stack<letter *> work_temp;
    std::stack<letter *> hobby_temp;
    std::stack<letter *> family_temp;
    
    std::stack<std::stack<letter*> > stackOfStacks;
    stackOfStacks.push(tray_work);
    stackOfStacks.push(tray_hobby);
    stackOfStacks.push(tray_family);
    
    while (! stackOfStacks.empty()) {
        std::stack<letter *> cleanningTray = stackOfStacks.top();
        while (! cleanningTray.empty()) {
            letter *topelement = cleanningTray.top();
            std::string tray = topelement->getTray();
            if (tray == "work") {
                work_temp.push(topelement);
            } else if (tray == "hobby") {
                hobby_temp.push(topelement);
            } else {
                family_temp.push(topelement);
            }
            cleanningTray.pop();
        }
        stackOfStacks.pop();
    }
    
    tray_family = family_temp;
    tray_hobby = hobby_temp;
    tray_work = work_temp;
    
 }

int getMaximumPriority(std::stack<letter*> _tray) {
    int mp = -1;
    
    while (!_tray.empty()) {
        int tp = _tray.top()->getPriority();
        if (tp > mp) mp = tp;
        _tray.pop();
    }
    return mp;
}

std::stack<letter*> orderByPriority(std::stack<letter*> tray_){
    /* 
     * I'm using an adapted bucketsort.
     * I'm aware of the memory usage. Not the best solution.
     */
    int size = getMaximumPriority(tray_);
    std::stack<letter*> *stackAr = new std::stack<letter*>[size];
    
    while (!tray_.empty()) {
        letter *te = tray_.top();
        stackAr[te->getPriority()].push(te);
        tray_.pop();
    }
    
    std::stack<letter*> tempStack;
    
    for (int i = size - 1; i >= 0; i--) {
        while (!stackAr[i].empty()) {
            tempStack.push(stackAr[i].top());
            stackAr[i].pop();
        }
    }
    delete[] stackAr;
    return tempStack;
    
}
