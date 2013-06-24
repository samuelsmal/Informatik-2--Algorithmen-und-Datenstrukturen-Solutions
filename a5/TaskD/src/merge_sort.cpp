#include <iostream>
#include "merge_sort.h"

// Split a vector into two parts and recursively call merge() on each of them
void
merge_sort (std::vector < int >&numbers)
{
    if (numbers.size() >= 2) {
        std::vector<int> lo(numbers.begin(), numbers.begin() + numbers.size() / 2);
        std::vector<int> hi(numbers.begin() + numbers.size() / 2 + 1, numbers.end());
        merge_sort(lo);
        merge_sort(hi);
        merge(lo, hi, numbers);
    }
}

// Merge two sorted lists (numbers1 and numbers2) into one sorted list (numbers)
void
merge (std::vector < int >&numbers1, std::vector < int >&numbers2,
       std::vector < int >&numbers)
{
    //TODO: fill in your code here
    std::vector<int>::const_iterator itr1 = numbers1.begin();
    std::vector<int>::const_iterator itr2 = numbers2.begin();
    
    
    while (itr1 != numbers1.end() || itr2 != numbers1.end()) {
        if (itr1 < numbers1.end()) {
            if (itr2 < numbers2.end()) numbers.push_back(*itr1 < *itr2 ? *itr1++ : *itr2++);
            else numbers.push_back(*itr1++);
        } else numbers.push_back(*itr2++);
    }
}
