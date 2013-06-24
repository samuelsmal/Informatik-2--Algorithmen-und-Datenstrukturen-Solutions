//
//  main.cpp
//  Vectors
//
//  Created by Loc Nguyen on 23.02.12.
//  Copyright (c) 2012 Universität Zürich. All rights reserved.
//

#include <iostream>
#include "vectors.cpp"

int main (int argc, const char * argv[])
{
    
    ArrayVector<int> my_vector;
    
    for (int i=0; i<15; i++) {
        my_vector.insertAtRank(i, i*2+2);
        std::cout<<"in slot " << i << " is the number " << my_vector.elemAtRank(i) << "\n";
    };
    
    my_vector.removeAtRank(10);
    my_vector.removeAtRank(1);
    my_vector.removeAtRank(12);
    
    std::cout <<"show vector after some removals\n";
    
    for (int i=0; i<12; i++) {
        std::cout<<"in slot " << i << " is the number " << my_vector.elemAtRank(i) << "\n";

    }

    //own Example here!
    ArrayVector<double> example;
    std::cout << "own example\n";
    
    for (int i = 0; i < 100; i++) {
        example.insertAtRank(i, (double)i/32.1);
    }    
    for (int i = 0; i < 100; i += 3) {
        example.removeAtRank(i);
    }
    for (int i = 0; i < 65; i++) {
        std::cout<<"in slot " << i << " is the number " << example.elemAtRank(i) << "\n";
    }
    
    return 0;
}
