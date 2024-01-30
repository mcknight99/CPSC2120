//Linker to use the infix to postfix
#include <string>

int getPrecedence(char operatorChar);
bool isOperator(char c);
int infixToPostfix(std::string infix[], int length, std::string postfix[]);
