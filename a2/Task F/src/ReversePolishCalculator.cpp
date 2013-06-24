//
//  ReversePolishCalculator.cpp
//  Stacks
//
//  Created by Rafael Ballester on 15/01/13.
//  Copyright 2013 Universität Zürich. All rights reserved.
//

#include <iostream>
#include "ReversePolishCalculator.h"

void ReversePolishCalculator::introduceNumber(int input) {
    internalStack.push(input);
}

void ReversePolishCalculator::operate(std::string operatorString) {
    if (internalStack.size() >= 2) {
        int a = internalStack.top();
        internalStack.pop();
        int b = internalStack.top();
        internalStack.pop();
        
        if (operatorString == "+") {
            internalStack.push(a + b);
        } else if (operatorString == "-") {
            internalStack.push(a - b);
        } else if (operatorString == "*") {
            internalStack.push(a * b);
        } else if (operatorString == "/"){
            internalStack.push(a / b);
        } else {
            std::cout << "Error: Command not recognized!";
        }
    }
}

void ReversePolishCalculator::printResult() {
    // M2C: should compute the result and not just return something.
    
    std::cout << "Result = " << internalStack.top() << std::endl;
    internalStack.pop();
}
