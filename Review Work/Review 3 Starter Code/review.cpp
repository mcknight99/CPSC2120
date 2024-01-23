#include "review.h"

#include <iostream>
#include <cstring> //for strcmp() and c_str()

void ReadStdIn2() {

    std::cout<<"Reading in. Enter 'q' to quit and sum read in count:"<<std::endl; //Again, auto grader does not like couts. Comment out when submitting

    int count = -1; //Starting at -1 for the do-while loop, because it increments whether or not the first entry is a q. So if the first entry is a q, it'll say 0 entries
    //starting it at 0 would mean copying a few lines outside of the do-while, making it a while, and only having count++ inside the while

    std::string userInput;
    do{
        std::cin>>userInput;
        count++;
    }while(strcmp(userInput.c_str(), "q")!=0); // If the user input is exactly 'q' then quit the loop.

    std::cout<<count<<std::endl;

}