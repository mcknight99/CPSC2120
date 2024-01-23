#include "ListQueue.h"

using namespace std;
#include <iostream>

int main()
{
    ListQueue<string> queue1;
    for (int i=0; i<13; i++){
        queue1.enqueue("frankline");
    }
    queue1.dequeue();

    if (queue1.size() != 12)
    {
        cout << "expected/correct value 12, actual value when testing " << queue1.size() << ".\n";
        return 1;
    }
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPassed" << endl;
    return 0;
}