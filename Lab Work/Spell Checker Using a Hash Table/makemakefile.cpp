#include <iostream>
#include <fstream>

int main()
{
    // Open the Makefile for writing
    std::ofstream makefile("makefile");

    if (makefile.is_open())
    {

        int numList[] = {1,2,3,4,5,6,7,8,9,16,17,18,21,22,23};

        // Write some content to the Makefile
        makefile << "compile:\n";
            makefile << "\tg++ stringset.cpp -Wall -c -o \"stringset.o\"\n";
        for (size_t i = 0; i < std::size(numList); i++)
        {
            makefile << "\tg++ \"T" << numList[i] << ".cpp\" -Wall stringset.o -o \"T" << numList[i] << ".exe\"\n";
        }
        makefile << "\nrun:\n";
        for (size_t i = 0; i < std::size(numList); i++)
        {
            makefile << "\t.\\T" << numList[i] << ".exe\n";
        }
        makefile << "\nclean:\n\tdel *.exe\n\tdel *.o\n";
        makefile << "\nremake:\n\tg++ makemakefile.cpp -o \"remake.exe\" -Wall\n\t.\\remake.exe\n\tdel remake.exe";

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
