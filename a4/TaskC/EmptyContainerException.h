//
//  EmptyContainerException.h
//  TaskC
//
//  Created by Samuel von Bausznern on 18.04.13.
//
//

#ifndef __TaskC__EmptyContainerException__
#define __TaskC__EmptyContainerException__

#include <iostream>

class EmptyContainerException {
    
    
public:
    EmptyContainerException();
    std::string getMessage();
};

#endif /* defined(__TaskC__EmptyContainerException__) */
