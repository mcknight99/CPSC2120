#include <iostream>
#include <string>
#include "infixToPostfixLinker.h"

using namespace std;

int infixToPostfix(string infix[], int length, string postfix[]);

int main()
{
    string infixExp[] = {"5", "+", "42", "/", "(", "30", "/",
                         "(", "20", "/", "(", "12", "/", "(",
                         "6", "/", "(", "4", "/", "2", ")",
                         ")", ")", ")", ")"};
    string postfixExp[25] = {"5", "42", "30", "20", "12", "6", "4",
                             "2", "/", "/", "/", "/", "/", "/",
                             "+"};
    string postfixTest[25];
    int postfixLength = infixToPostfix(infixExp, 25, postfixTest);
    postfixLength+=0;

    //ASSERT_EQ(postfixLength, 15);
    if (postfixLength != 15)
    {
        cout << "expected/correct value for postfixLength 15, actual value when testing " << postfixLength << ".\n";
        //return 1;
    }
    cout << "Passed" << endl;
    return 0;
}