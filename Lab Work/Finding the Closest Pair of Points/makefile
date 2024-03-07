compile:
	g++ closestPair.cpp -c -o "FILETOINCLUDE.o" -Wall
	g++ "T1.cpp" -Wall -o "T1.exe" FILETOINCLUDE.o
	g++ "T2.cpp" -Wall -o "T2.exe" FILETOINCLUDE.o
	g++ "T6.cpp" -Wall -o "T6.exe" FILETOINCLUDE.o

run:
	.\T1.exe
	.\T2.exe
	.\T6.exe

clean:
	del *.exe
	del *.o

remake:
	g++ makemakefile.cpp -o "remake.exe" -Wall
	.\remake.exe
	del remake.exe
