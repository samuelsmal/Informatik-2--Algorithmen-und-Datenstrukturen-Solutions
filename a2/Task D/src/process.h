/*
 Assignment 2 - Algorithms and data structures
 
 University of Zurich
 Department of Informatics
 Vizualization and Multimedia Laboratory
 
 Author: Genc Mazlami
 */

#ifndef process_queue_process_h
#define process_queue_process_h


#include <string>

class process{
    
private:
    
    int _id; 
    
    std::string _description;
    
public:
    
    process(int id,std::string description);
    
    int get_id();
    
    std::string get_description();
    
};



#endif
