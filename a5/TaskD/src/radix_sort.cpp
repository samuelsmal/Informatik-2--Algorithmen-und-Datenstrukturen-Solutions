//
//  radix_sort.cpp
//  radixsort
//
//  Created by Loc Nguyen on 19.04.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//
#include <limits>
#include "radix_sort.h"

template <typename T>
bool getBit(T in, int pos) {
    return (in & ( 1 << pos )) >> pos;
}

template <typename T>
void radix_sort_binary(std::vector<T>& in) {
    size_t bitSizeOfType = sizeof(in[0])*CHAR_BIT;
    /**
     * Way to many... CHAR_BIT is required so this will work on all platforms. One byte != 8 bits!
     * A char is always one byte , but it's not always an octet.
     * A byte is the smallest addressable unit of memory (in most definitions), an octet is 8-bit unit of memory.
     */
    for (int i = 0; i < bitSizeOfType; i++) {w
        std::vector<std::vector<T> > buckets(2);
        for (std::vector<int>::iterator itr = in.begin(); itr != in.end(); itr++) {
            if (!getBit(*itr, i)) buckets[0].push_back(*itr);
            else buckets[1].push_back(*itr);
        }
        // restructuring the input vector.
        std::vector<int>::iterator in_itr = in.begin();
        for (int j = 0; j < 2; j++) {
            for (std::vector<int>::const_iterator buckets_itr = buckets[j].begin(); buckets_itr != buckets[j].end(); buckets_itr++) {
                *in_itr++ = *buckets_itr;
            }
        }
    }
}

void radix_sort_digitwise(std::vector<int>& in) {
    int max_value = 1;      // To determine the number of runs needed.
    bool firstrun = true;
    
    typedef std::vector<int>::iterator int_itr;
    typedef std::vector<int>::const_iterator const_int_itr;

    for (int offset = 1; max_value > 0; offset *= 10, max_value -= (max_value / offset % 10)) { // run-time error. offset == 0. why on earth?
        // Filling the buckets.
        std::vector<std::vector<int> > tmp(10);
        for (int_itr itr = in.begin(); itr != in.end(); itr++) {
            if (firstrun) {
                max_value = max_value < *itr ? *itr : max_value;
            }
            tmp.at((*itr) / offset % 10).push_back(*itr);
        }
        
        firstrun = false;
        
        // refilling the array.
        int_itr in_itr = in.begin();
        for (std::vector<std::vector<int> >::const_iterator outer_itr = tmp.begin(); outer_itr != tmp.end(); outer_itr++) {
            for (const_int_itr inner_itr = outer_itr->begin(); inner_itr != outer_itr->end(); inner_itr++) {
                *in_itr = *inner_itr;
            }
        }
    }
}

void
radix_sort (std::vector < int >&input_list)
{
    //radix_sort_binary(input_list);
    radix_sort_digitwise(input_list);
}






