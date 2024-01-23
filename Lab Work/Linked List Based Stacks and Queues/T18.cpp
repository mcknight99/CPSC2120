#include "ListStack.h"

using namespace std;
#include <iostream>

int main()
{
    ListStack<char> stack4;
    char a = 'A';
    for(int i = 1, j = 1; i <= 17; i++){
        stack4.push(a);
        a++;
    }
    int k = stack4.pop();

    if (stack4.size() != 16)
    {
        cout << "expected/correct value 6, actual value when testing " << stack4.size() << ".\n";
        return 1;
    }
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPassed" << endl;
    return 0;
}