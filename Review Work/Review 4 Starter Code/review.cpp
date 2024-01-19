#include "review.h"

#include <iostream>
#include <cstring> //for strcmp() and c_str()

void ReadWrite()
{

    // std::cout<<"Reading in. Enter 'q' to quit and sum read in count:"<<std::endl; //Again again, auto grader does not like couts

    std::vector<std::string> userInputVector;

    std::string userInput;
    do
    {
        std::cin >> userInput;
        userInputVector.push_back(userInput);
    } while (strcmp(userInput.c_str(), "q") != 0); // If the user input is exactly 'q' then quit the loop.

    for (std::string i : userInputVector)
    {
        if (strcmp(i.c_str(), "q") != 0) //Because q is appended to the vector, don't print if the entry is q
        {
            std::cout << i << ' ';
        }
    }
    std::cout << std::endl;
}