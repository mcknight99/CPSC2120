/*
 * Name: Sam Pupke
 * Date Submitted: Feb 5 2024
 * Lab Section: 002
 * Assignment Name: Lab 2: Infix to Postfix Conversion
 */

#include <string>
#include <stack>
#include <iostream>
#include <unordered_map> //for making precendence cleaner

using namespace std;

// get the precedence of one of the operators
int getPrecedence(char operatorChar)
{
    // turns out precedence is very strange to type several times
    // it no longer looks like a word to me
    unordered_map<char, int> precedence;
    precedence['+'] = 1;
    precedence['-'] = 1;
    precedence['*'] = 2;
    precedence['/'] = 2;
    precedence['%'] = 2;
    return precedence[operatorChar];
}

//returns true if the char is one of the five operators
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// Converts an infix arithmetic expression into postfix
// The function takes 3 parameters
// First parameter: array of strings for infix expression
//     each string is either an integer number or operator symbol
// Second parameter: number of strings in infix expression
// Third parameter: array of strings for postfix expression
//     generated by function, same format as first parameter
//     assumes that postfix is at least the size of postfix
// Return value: int, number of strings in postfix expression
//     Returns 0 if an error is encountered when converting expression
//     An error occurs with a mismatched parenthesis, e.g. ( ( ) or ( ) ) etc.
// Operator symbols:
//  ( : left parenthesis, all operations between this and ")" take place first
//  ) : right parenthesis, all op.s back to previous "(" take place first
//  * : multiplication, higher precedence - takes place before "+" and "-"
//  / : division, higher precedence - takes place before "+" and "-"
//  % : remainder, higher precedence - takes place before "+" and "-"
//  + : addition, lower precedence - takes place after "*" , "/" , "%"
//  - : subtraction, lower precedence - takes place after "*" , "/" , "%"
// The function is not specified to work with any other operator symbols
// Any string in infix may be assumed to be an integer operand if none
//  of the above symbols
int infixToPostfix(string infix[], int length, string postfix[])
{
    stack<char> operators;
    int postfixIndex=0;
    for(int i = 0; i<length; i++) {
        string token = infix[i];

        if(token=="(") {
            operators.push('(');
        } else if(token==")") {
            while(!operators.empty() && operators.top() != '(') {
                postfix[postfixIndex] = operators.top();
                postfixIndex++;
                operators.pop(); //pop is a void function >:(
            }

            if(operators.empty()) {
                //mismatched parentheses by finding an end with no start
                return 0;
            }

            operators.pop();
        } else if(isOperator(token[0])) { //[0] to convert str to a char for the function
            while(!operators.empty() && getPrecedence(operators.top())>= getPrecedence(token[0])) {
                postfix[postfixIndex] = operators.top();
                postfixIndex++;
                operators.pop();
            }
            operators.push(token[0]);
        } else {
            //operand
            postfix[postfixIndex] = token;
            postfixIndex++;
        }
    }

    while(!operators.empty()) {
        if(operators.top()=='(') {
            //mismatched parenthesis by finding a start with no end
            return 0;
        }
        postfix[postfixIndex] = operators.top();
        postfixIndex++;
        operators.pop();
    }
    return postfixIndex;

}


//Submission required main to be commented out when submitted
// Main function to test infixToPostfix()
// Should convert 2 + 3 * 4 + ( 5 - 6 + 7 ) * 8
//             to 2 3 4 * + 5 6 - 7 + 8 * +
/*
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
*/
