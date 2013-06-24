/* Basic Exercise - Algorithms and Datastructures
 * University of Zurich
 * Author: Genc Mazlami 09-923-061
 * Updated by Rafael Ballester on 10.01.13.
 * 
 */	

#include <cstdlib>
#include <string>
#include <iostream>

//TASK 1)*************************************
int getSize(char* string) {
	
	//TODO: fill in your code here 
}
//********************************************

//TASK 2)*************************************
void concatenate(char str1[], char str2[]) {
	
	//TODO: fill in your code here
}
//********************************************

//TASK 3)*************************************
bool isPalindrome(std::string str) {
	
    //TODO: fill in your code here
}
//********************************************

//TASK 4)*************************************
void printShape(int level, char character) {

    //TODO: fill in your code here
}
//********************************************

//If you want to make changes to the main-function to test your results, you can. But please comment out or delete your changes before
// submitting the exercise.
int main(int argc, char** argv) {
	
    //Testing task 2)
    std::cout << std::endl << std::endl;
    std::cout << "TASK 1)" << std::endl;
    std::cout << "---------------------" << std::endl;
    
    char example[] = "abcdef";
    std::cout << "The size of " << example << " is " << getSize(example);
    
    //Testing task 2)
    std::cout << std::endl << std::endl;
    std::cout << "TASK 2)" << std::endl;
    std::cout << "---------------------" << std::endl;
    
    char str1[] = "Let's concatenate this string ";
    char str2[] = "with this one.";
    concatenate(str1,str2);
    
    
    //Testing task 3)
    std::cout << std::endl << std::endl;
    std::cout << "TASK 3)" << std::endl;
    std::cout << "---------------------" << std::endl;
    
    std::string myString = "aabbcbbaa";
    if (isPalindrome(myString))
        std::cout << myString << " is a palindrome" << std::endl;
    else
        std::cout << myString << " is not a palindrome" << std::endl;
    myString = "aabcdaa";
    if (isPalindrome(myString))
        std::cout << myString << " is a palindrome" << std::endl;
    else
        std::cout << myString << " is not a palindrome" << std::endl;

    //Testing task 4)
    std::cout << std::endl << std::endl;
    std::cout << "TASK 4)" << std::endl;
    std::cout << "---------------------" << std::endl;

    printShape(9,'*');
	
    return 0;
}
