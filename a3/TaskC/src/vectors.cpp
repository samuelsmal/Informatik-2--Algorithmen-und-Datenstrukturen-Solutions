//
//  vectors.cpp
//  Vectors
//
//  Created by Loc Nguyen on 24.02.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//


#include "vectors.h"
template <typename Object>
ArrayVector<Object>::ArrayVector(int initCap) : capacity(initCap), numberOfElements(0) {
    array = new Object[capacity];
}

template <typename Object>
ArrayVector<Object>::~ArrayVector() {
    delete array;
}

template <typename Object>
int ArrayVector<Object>::size() const {
    return numberOfElements;
}

template <typename Object>
bool ArrayVector<Object>::isEmpty() const {
    return numberOfElements == 0;
}

template <typename Object>
Object& ArrayVector<Object>::elemAtRank(int r) {
    if (r < numberOfElements && r >= 0 && array[r]) {
        return array[r];
    }
}

template <typename Object>
void ArrayVector<Object>::replaceAtRank(int r, const Object& e) {
    if (r >= 0 && r < capacity) {
        array[r] = e;
    }
}

template <typename Object>
void ArrayVector<Object>::removeAtRank(int r) {
    if (r < capacity && r >= 0) {
        for (int i = r; i < capacity - 1; i++) {
            array[i] = array[i + 1];
        }
        numberOfElements--;
    }
}

template <typename Object>
void ArrayVector<Object>::insertAtRank(int r, const Object &e) {
    if (r >= 0) {
        while (r + 1 > capacity) {
            ArrayVector<Object>::overflow();
        }
        array[r] = e;
        numberOfElements++;
    }
}

template <typename Object>
void ArrayVector<Object>::overflow() {
    int newCap = 2 * capacity;
    Object *newAr = new Object[newCap];
    for (int i = 0; i < capacity; i++) {
        newAr[i] = array[i];
    }
    array = newAr;
    capacity = newCap;
}




