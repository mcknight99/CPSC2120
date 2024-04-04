compile:
	g++ bstSequence.cpp -c -o "bstSequence.o" -Wall
	g++ "T1.cpp" -Wall -o "T1.exe" bstSequence.o
	g++ "T3.cpp" -Wall -o "T3.exe" bstSequence.o
	g++ "T4.cpp" -Wall -o "T4.exe" bstSequence.o
	g++ "T6.cpp" -Wall -o "T6.exe" bstSequence.o
	g++ "T7.cpp" -Wall -o "T7.exe" bstSequence.o
	g++ "T9.cpp" -Wall -o "T9.exe" bstSequence.o
	g++ "T10.cpp" -Wall -o "T10.exe" bstSequence.o
	g++ "T12.cpp" -Wall -o "T12.exe" bstSequence.o

run:
	.\T1.exe
	.\T3.exe
	.\T4.exe
	.\T6.exe
	.\T7.exe
	.\T9.exe
	.\T10.exe
	.\T12.exe

clean:
	del *.exe
	del *.o

remake:
	g++ makemakefile.cpp -o "remake.exe" -Wall
	.\remake.exe
	del remake.exe
