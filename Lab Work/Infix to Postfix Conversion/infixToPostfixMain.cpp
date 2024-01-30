/*
 * Name: Sam Pupke
 * Date Submitted: Feb 5 2024
 * Lab Section: 002
 * Assignment Name: Lab 2: Infix to Postfix Conversion
 */

#include <string>
#include <stack>
#include <iostream>
#include "infixToPostfixLinker.h"
using namespace std;

// Main function to test infixToPostfix()
// Should convert 2 + 3 * 4 + ( 5 - 6 + 7 ) * 8
//             to 2 3 4 * + 5 6 - 7 + 8 * +
int main()
{
    string infixExp[] = {"2", "+", "3", "*", "4", "+", "(",
                         "5", "-", "6", "+", "7", ")", "*",
                         "8"};
    string postfixExp[15];
    int postfixLength;

    cout << "Infix expression: ";
    for (int i = 0; i < 15; i++)
    {
        cout << infixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: 15" << endl
         << endl;

    postfixLength = infixToPostfix(infixExp, 15, postfixExp);

    cout << "Postfix expression: ";
    for (int i = 0; i < postfixLength; i++)
    {
        cout << postfixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: " << postfixLength << endl;

    return 0;
}


