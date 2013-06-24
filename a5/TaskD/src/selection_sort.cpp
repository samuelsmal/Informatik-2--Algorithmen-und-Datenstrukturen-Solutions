//
//  Created by Rafael Ballester on 10.04.13.
//  Copyright (c) 2013 Universität Zürich. All rights reserved.
//

#include <iostream>
#include "selection_sort.h"

void
selection_sort (std::vector < int >&numbers)
{
    typedef std::vector<int>::iterator int_itr;
    int_itr current_min_pos;
    int swap;
    for (int_itr outer_itr = numbers.begin(); outer_itr != numbers.end(); outer_itr++) {
        current_min_pos = outer_itr;
        for (int_itr inner_itr = outer_itr + 1; inner_itr < numbers.end(); inner_itr++) {
            if (*current_min_pos > *inner_itr) current_min_pos = inner_itr;
        }
        
        if (current_min_pos != outer_itr) {
            swap = *current_min_pos;
            *current_min_pos = *outer_itr;
            *outer_itr = swap;
        }
    }
}
