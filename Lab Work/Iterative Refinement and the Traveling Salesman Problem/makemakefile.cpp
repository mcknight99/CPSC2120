#include <iostream>
#include <fstream>

// Idea to add: another list for files to include instead of manually replacing FILETOINCLIDE, 
// having a list of strings that get compiled to .o and linked to the test files

int main()
{
    // Open the Makefile for writing
    std::ofstream makefile("makefile");

    if (makefile.is_open())
    {

        int numList[] = {1,3};

        // Write some content to the Makefile
        makefile << "compile:\n";
        makefile << "\tg++ tspRefine.cpp -c -o \"tspRefine.o\" -Wall\n"; //repeat this as many times as needed for object files and add the .o to the T maker
        for (size_t i = 0; i < std::size(numList); i++)
        {
            makefile << "\tg++ \"T" << numList[i] << ".cpp\" -Wall -o \"T" << numList[i] << ".exe\" tspRefine.o\n";
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
