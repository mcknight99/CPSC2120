compile:
	g++ tspRefine.cpp -c -o "tspRefine.o" -Wall
	g++ "T1.cpp" -Wall -o "T1.exe" tspRefine.o
	g++ "T3.cpp" -Wall -o "T3.exe" tspRefine.o

run:
	.\T1.exe
	.\T3.exe

clean:
	del *.exe
	del *.o

remake:
	g++ makemakefile.cpp -o "remake.exe" -Wall
	.\remake.exe
	del remake.exe
