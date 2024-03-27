compile:
	g++ binarySearchTree.cpp -c -o "binarySearchTree.o" -Wall
	g++ "T1.cpp" -Wall -o "T1.exe" binarySearchTree.o
	g++ "T3.cpp" -Wall -o "T3.exe" binarySearchTree.o
	g++ "T4.cpp" -Wall -o "T4.exe" binarySearchTree.o
	g++ "T8.cpp" -Wall -o "T8.exe" binarySearchTree.o
	g++ "T9.cpp" -Wall -o "T9.exe" binarySearchTree.o
	g++ "T10.cpp" -Wall -o "T10.exe" binarySearchTree.o
	g++ "T12.cpp" -Wall -o "T12.exe" binarySearchTree.o
	g++ "T14.cpp" -Wall -o "T14.exe" binarySearchTree.o
	g++ "T15.cpp" -Wall -o "T15.exe" binarySearchTree.o
	g++ "T16.cpp" -Wall -o "T16.exe" binarySearchTree.o
	g++ "T18.cpp" -Wall -o "T18.exe" binarySearchTree.o

run:
	.\T1.exe
	.\T3.exe
	.\T4.exe
	.\T8.exe
	.\T9.exe
	.\T10.exe
	.\T12.exe
	.\T14.exe
	.\T15.exe
	.\T16.exe
	.\T18.exe

clean:
	del *.exe
	del *.o

remake:
	g++ makemakefile.cpp -o "remake.exe" -Wall
	.\remake.exe
	del remake.exe
