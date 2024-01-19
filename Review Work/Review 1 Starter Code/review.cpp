#include "review.h"

#include <iostream>

void ReadStdIn() {

    //std::cout<<"Please input your 3 inputs (integer, double, single word string):\n"; //Autograder doesn't like this but it is good for the user

    int integerInput;
    double doubleInput;
    std::string stringInput;
    
    std::cin>>integerInput>>doubleInput>>stringInput;
    
    std::cout<<integerInput<<std::endl;
    std::cout<<doubleInput<<std::endl;
    std::cout<<stringInput<<std::endl;

}