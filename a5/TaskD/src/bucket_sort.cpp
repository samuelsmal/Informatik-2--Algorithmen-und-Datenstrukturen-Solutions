//
//  Created by Rafael Ballester on 10.04.13.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#include <iostream>
#include "bucket_sort.h"

void
bucket_sort (std::vector < int >&numbers)
{
    std::vector<int>::size_type max = 0;
    for (std::vector<int>::const_iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
        if (*itr > max) {
            max = *itr;
        }
    }
    
    std::vector<int> ret(max);
    
    for (std::vector<int>::const_iterator itr = numbers.begin(); itr != numbers.end(); itr++) {
        ret[*itr]++;
    }
    
    numbers.clear();
    for (int i = 0; i < max; i++) {
        for (int count = ret[i]; count > 0; count--) {
            numbers.push_back(i);
        }
    }
}
