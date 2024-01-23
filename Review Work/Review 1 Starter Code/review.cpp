#include "review.h"

#include <iostream>

void ReadStdIn() {

    std::cout<<"Please input your 3 inputs (integer, double, single word string):\n"; //Autograder doesn't like this, comment it out when submitting

    int integerInput;
    double doubleInput;
    std::string stringInput;
    
    std::cin>>integerInput>>doubleInput>>stringInput;
    
    std::cout<<integerInput<<std::endl;
    std::cout<<doubleInput<<std::endl;
    std::cout<<stringInput<<std::endl;

}