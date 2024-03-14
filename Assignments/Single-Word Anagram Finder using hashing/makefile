compile:
	g++ anagram.cpp -c -o "anagram.o" -Wall
	g++ "T1.cpp" -Wall -o "T1.exe" anagram.o
	g++ "T2.cpp" -Wall -o "T2.exe" anagram.o
	g++ "T3.cpp" -Wall -o "T3.exe" anagram.o
	g++ "T4.cpp" -Wall -o "T4.exe" anagram.o
	g++ "T5.cpp" -Wall -o "T5.exe" anagram.o
	g++ "T6.cpp" -Wall -o "T6.exe" anagram.o

run:
	.\T1.exe
	.\T2.exe
	.\T3.exe
	.\T4.exe
	.\T5.exe
	.\T6.exe

clean:
	del *.exe
	del *.o

remake:
	g++ makemakefile.cpp -o "remake.exe" -Wall
	.\remake.exe
	del remake.exe
