//
//  Heap.cpp
//  Heap
//
//  Created by Loc Nguyen on 21.03.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
#include "Heap.h"
#include <iostream>
#include <stdexcept> // std::out_of_range

using std::vector;      using std::pair;
using std::string;      using std::swap;
using std::distance;

template<typename Key, typename Element>
MyHeap<Key, Element>::MyHeap(int _capacity) {
    const item i = item(INT_MIN, "");
    heap.push_back(i);
    heap.reserve(_capacity);
}

template<typename Key, typename Element>
int MyHeap<Key, Element>::size() const{
    return heap.size() - 1; // should return a size_type and not an int!
}

template<typename Key, typename Element>
bool MyHeap<Key, Element>::isEmpty() const {
    return heap.size() <= 1;
}

template<typename Key, typename Element>
const string& MyHeap<Key, Element>::minElement() const throw(EmptyContainerException) {
    if (this->isEmpty()) {
        throw EmptyContainerException();
    }
    
    return heap.at(1).second;
}

template<typename Key, typename Element>
const int& MyHeap<Key, Element>::minKey() const throw(EmptyContainerException) {
    if (this->isEmpty()) throw EmptyContainerException();
    
    return heap.at(1).first;
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::insertItem(const Key& k, const Element& e) {
    heap.push_back(item(k, e));
        
    iterator parent = heap.end() - distance(heap.begin()++, heap.end()) / 2;
    if (parent > heap.end()) {
        parent = heap.begin();
    }
    iterator child = heap.end();
    
    
    while (child->first < parent->first) {
        swap(*child, *parent);
        child = parent;
        parent = child - distance(heap.begin()++, child) / 2;
    }
}

template<typename Key, typename Element>
void MyHeap<Key, Element>::removeMin() throw(EmptyContainerException) {
    if (this->isEmpty()) throw EmptyContainerException();
    
    heap.at(1) = heap.back();
    heap.pop_back();
    
    iterator parent = ++heap.begin();
    
    if (heap.size() > 1) {
        iterator left_child = ++parent;
        
        if (heap.size() > 2) {
            iterator right_child = ++left_child;
            
            while (parent->first > left_child->first || parent->first > right_child->first) {
                if (parent->first > left_child->first) {
                    swap(*parent, *left_child);
                    
                    parent = left_child;
                    left_child = getLeftChild(parent);
                    right_child = getRightChild(parent);
                    
                } else {
                    swap(parent, right_child);
                    
                    parent = right_child;
                    left_child = getLeftChild(parent);
                    right_child = getRightChild(parent);
                }
            }
        }
    
    }

}



