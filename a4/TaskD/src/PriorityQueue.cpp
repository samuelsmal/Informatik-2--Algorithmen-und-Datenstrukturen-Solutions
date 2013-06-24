/*
 Assignment 4 - Algorithms and data structures
 
 University of Zurich
 Department of Informatics
 Vizualization and Multimedia Laboratory
 
 Author: Genc Mazlami
 */

#include <iostream>
#include "PriorityQueue.h"


#include <algorithm>    // std::make_heap, std::pop_heap, std::push_heap, std::sort_heap


PriorityQueue::PriorityQueue(){
    
    //create queue and fill it with starting elements
    queue.push_back(99);
    queue.push_back(3);
    queue.push_back(45);
    queue.push_back(2);
    queue.push_back(13);
    
    
    std::make_heap(queue.begin(), queue.end());   // build heap order on the queue, so that greatest element is on top
    
    
}





int PriorityQueue::getFrontElement(){  //return the topelement
    
    return queue.at(0);
    
}



void PriorityQueue::insert(int _element){
    

    //TODO: insert code here
    queue.push_back(_element);
    std::push_heap(queue.begin(), queue.end());
}


void PriorityQueue::remove(){
    
    //TODO: insert code here
    std::pop_heap(queue.begin(), queue.end());
    queue.pop_back();
}


void PriorityQueue::heapsort(){
    //TODO: insert code here
    std::sort_heap(queue.begin(), queue.end());
}

void PriorityQueue::printQueue(){
    std::cout << "Current Queue: " << std::endl;
    
   
    //TODO: insert code here
    for (std::vector<int>::const_iterator itr = queue.begin();
         itr != queue.end(); ++itr)
    {
        std::cout << *itr << ' ';
    }
    
    
    std::cout << std::endl;
}


