#include "review.h"

#include <iostream>

int WriteOut(std::string output) {
    std::cout<<output<<std::endl;
    return 1;
}

int WriteOut(int output) {
    std::cout<<output<<std::endl;
    return 2;
}

int WriteOut(double output) {
    std::cout<<output<<std::endl;
    return 3;
}