//
//  Heap.h
//  Heap
//
//  Created by Loc Nguyen on 20.03.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <string>
#include <stdexcept>    // std::out_of_range
#include <climits>      // for INT_MIN
#include <iterator>

#include "EmptyContainerException.h"

// bad, very bad style! since the .h-file will be inluded in other files!
/*
using std::vector;
using std::pair;
using std::string; 
 */

template <typename Key, typename Element>
class MyHeap {
    typedef std::pair<Key, Element> item;
    typedef std::vector<item> vector_type;
    typedef typename vector_type::iterator iterator;
    
    std::vector<item> heap;
    // sorry for the bad style. i was tired and the compiler is unnerving.
    iterator getLeftChild(iterator parent) {
        iterator ret = heap.begin() + 1 + std::distance(heap.begin(), parent) * 2;
        
        if (ret > heap.end()) {
            ret = heap.begin();
        }

        return ret;
    }
    
    iterator getRightChild(iterator parent) {
        iterator ret = heap.begin() + 2 + std::distance(heap.begin(), parent) * 2;
        
        if (ret > heap.end()) {
            ret = heap.begin();
        }
        
        return ret;
    }
    
public:
    MyHeap(int capac = 100);		
    int size() const;					
    bool isEmpty() const;					
    
    const std::string& minElement() const throw(EmptyContainerException) ;
    const int& minKey() const throw(EmptyContainerException) ;	    
    void insertItem(const Key& k, const Element& e);
    void removeMin() throw(EmptyContainerException);
};
#endif
