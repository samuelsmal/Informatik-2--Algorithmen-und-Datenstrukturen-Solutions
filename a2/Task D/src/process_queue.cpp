/*
 Assignment 2 - Algorithms and data structures
 
 University of Zurich
 Department of Informatics
 Vizualization and Multimedia Laboratory
 
 Author: Genc Mazlami
 */

#include <iostream>
#include "process_queue.h"
#include "process.h"


process_queue::process_queue(){
    _tail_index = -1;
}

int process_queue::get_size(){
    return _tail_index + 1;
}

bool process_queue::is_empty(){
    return _tail_index == -1;
}

void process_queue::add(process *my_process){

    if (_tail_index > MAX_SIZE - 1) {
        std::cout << "Error. MAX SIZE reached!";
        return;
    }
    _processes[++_tail_index] = my_process;
}

process* process_queue::remove(){
    return _processes[_tail_index--];
}
