#include <string>
#include <stack>

using namespace std;

// Calculates a postfix expression with integer operands using a stack
// The expression is represented using an array of strings
// Each string is either an operand or operator symbol
// Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
// Example expression: "8", "5", "-" evaluates to a result of 3:
// 1: push 8, 2: push 5,
// 3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
// The result of the operation (8-5) is 3, push 3 onto stack
// After evaluation of the expression, the final result should be
// the only value on the stack, return 0 if the stack is
// non-empty after popping the result
// Return 0 if expression is zero-length or if there are insufficient operands
// for an operation
// The STL Stack class can be used
// To easily convert a numeric string to an int you may use the stoi() function
// which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
    // Check for empty expression
    if (length == 0)
    {
        return 0;
    }

    stack<int> operandStack;

    for (int i = 0; i < length; ++i)
    {
        string token = expression[i];

        // Check if the token is an operand (numeric string)
        if (isdigit(token[0]) || (token.length() > 1 && token[0] == '-' && isdigit(token[1])))
        {
            operandStack.push(stoi(token));
        }
        else
        {
            // Token is an operator
            if (operandStack.size() < 2)
            {
                // Insufficient operands for the operation
                return 0;
            }

            int operand2 = operandStack.top();
            operandStack.pop();

            int operand1 = operandStack.top();
            operandStack.pop();

            // Perform the operation based on the operator symbol
            if (token == "+")
            {
                operandStack.push(operand1 + operand2);
            }
            else if (token == "-")
            {
                operandStack.push(operand1 - operand2);
            }
            else if (token == "*")
            {
                operandStack.push(operand1 * operand2);
            }
            else if (token == "/")
            {
                if (operand2 == 0)
                {
                    // Division by zero
                    return 0;
                }
                operandStack.push(operand1 / operand2);
            }
            else if (token == "%")
            {
                if (operand2 == 0)
                {
                    // Modulo by zero
                    return 0;
                }
                operandStack.push(operand1 % operand2);
            }
        }
    }

    // Check if there is only one result on the stack
    if (operandStack.size() == 1)
    {
        return operandStack.top();
    }

    return 0; // Stack is non-empty or insufficient operands
}