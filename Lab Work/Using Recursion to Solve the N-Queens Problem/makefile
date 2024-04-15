compile:
	g++ nQueens.cpp -c -o "nQueens.o" -Wall
	g++ "T1.cpp" -Wall -o "T1.exe" nQueens.o
	g++ "T2.cpp" -Wall -o "T2.exe" nQueens.o
	g++ "T4.cpp" -Wall -o "T4.exe" nQueens.o
	g++ "T7.cpp" -Wall -o "T7.exe" nQueens.o
	g++ "T8.cpp" -Wall -o "T8.exe" nQueens.o
	g++ "T9.cpp" -Wall -o "T9.exe" nQueens.o
	g++ "T11.cpp" -Wall -o "T11.exe" nQueens.o
	g++ "T12.cpp" -Wall -o "T12.exe" nQueens.o

run:
	.\T1.exe
	.\T2.exe
	.\T4.exe
	.\T7.exe
	.\T8.exe
	.\T9.exe
	.\T11.exe
	.\T12.exe

clean:
	del *.exe
	del *.o

remake:
	g++ makemakefile.cpp -o "remake.exe" -Wall
	.\remake.exe
	del remake.exe
