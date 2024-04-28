compile:
	g++ wordLadder.cpp -c -o "wordLadder.o" -Wall
	g++ "T1.cpp" -Wall -o "T1.exe" wordLadder.o
	g++ "T3.cpp" -Wall -o "T3.exe" wordLadder.o
	g++ "T5.cpp" -Wall -o "T5.exe" wordLadder.o
	g++ "T6.cpp" -Wall -o "T6.exe" wordLadder.o
	g++ "T7.cpp" -Wall -o "T7.exe" wordLadder.o
	g++ "T10.cpp" -Wall -o "T10.exe" wordLadder.o
	g++ "T11.cpp" -Wall -o "T11.exe" wordLadder.o
	g++ "T14.cpp" -Wall -o "T14.exe" wordLadder.o
	g++ "T15.cpp" -Wall -o "T15.exe" wordLadder.o

run:
	.\T1.exe
	.\T3.exe
	.\T5.exe
	.\T6.exe
	.\T7.exe
	.\T10.exe
	.\T11.exe
	.\T14.exe
	.\T15.exe

clean:
	del *.exe
	del *.o

remake:
	g++ makemakefile.cpp -o "remake.exe" -Wall
	.\remake.exe
	del remake.exe
