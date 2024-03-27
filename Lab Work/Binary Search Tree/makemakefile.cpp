#include <iostream>
#include <fstream>

int main()
{
    // Open the Makefile for writing
    std::ofstream makefile("makefile");

    if (makefile.is_open())
    {

        int numList[] = {1,3,4,8,9,10,12,14,15,16,18};

        // Write some content to the Makefile
        makefile << "compile:\n";
        makefile << "\tg++ binarySearchTree.cpp -c -o \"binarySearchTree.o\" -Wall\n"; //repeat this as many times as needed for object files and add the .o to the T maker
        for (size_t i = 0; i < std::size(numList); i++)
        {
            makefile << "\tg++ \"T" << numList[i] << ".cpp\" -Wall -o \"T" << numList[i] << ".exe\" binarySearchTree.o\n";
        }
        makefile << "\nrun:\n";
        for (size_t i = 0; i < std::size(numList); i++)
        {
            makefile << "\t.\\T" << numList[i] << ".exe\n";
        }
        makefile << "\nclean:\n\tdel *.exe\n\tdel *.o\n";
        makefile << "\nremake:\n\tg++ makemakefile.cpp -o \"remake.exe\" -Wall\n\t.\\remake.exe\n\tdel remake.exe\n";

        // Close the file
        makefile.close();

        std::cout << "Makefile written successfully.\n";
    }
    else
    {
        std::cerr << "Unable to open Makefile for writing.\n";
    }

    return 0;
}
