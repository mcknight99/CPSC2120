#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    List<int> list1;
    for(int i = 1, j = 1; i <= 10; i++){
        j = -2 * j;
        list1.insertStart(j);
    }
    list1.insertAt(3,0);

    // This can be an ofstream as well or any other ostream
    stringstream buffer;

    // Save cout's buffer here
    streambuf *sbuf = cout.rdbuf();

    // Redirect cout to our stringstream buffer or any other ostream
    cout.rdbuf(buffer.rdbuf());

    // Use cout as usual
    // cout << "Hello World";

    list1.print("list");

    int test[11];
    string bob;
    // This section skips the info printout 
    // section of the print function
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;
    buffer >> bob;

    int test2[] = {3,1024,-512,256,-128,64,-32,16,-8,4,-2};
    for (int i=0; i<11;i++){
        buffer >> bob;
        test[i] = stoi(bob);
        // ASSERT_EQ(test[i],test2[i]);
    }


    // When done redirect cout to its old self
    cout.rdbuf(sbuf);

    for (int i=0; i<11; i++)
    {
        if (test[i] != test2[i])
        {
            cout << "Mismatch at position " << i << ": expected/correct value " << test2[i] << ", actual value when testing " << test[i] << ".\n";
            return 1;
        }
    }
    cout << "\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tPassed" << endl;
    return 0;
}