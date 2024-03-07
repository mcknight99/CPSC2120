compile:
	g++ stringset.cpp -Wall -c -o "stringset.o"
	g++ main.cpp -Wall -c -o "main.o"
	g++ "T1.cpp" -Wall stringset.o main.o -o "T1.exe"
	g++ "T2.cpp" -Wall stringset.o main.o -o "T2.exe"
	g++ "T3.cpp" -Wall stringset.o main.o -o "T3.exe"
	g++ "T4.cpp" -Wall stringset.o main.o -o "T4.exe"
	g++ "T5.cpp" -Wall stringset.o main.o -o "T5.exe"
	g++ "T6.cpp" -Wall stringset.o main.o -o "T6.exe"
	g++ "T7.cpp" -Wall stringset.o main.o -o "T7.exe"
	g++ "T8.cpp" -Wall stringset.o main.o -o "T8.exe"
	g++ "T9.cpp" -Wall stringset.o main.o -o "T9.exe"
	g++ "T16.cpp" -Wall stringset.o main.o -o "T16.exe"
	g++ "T17.cpp" -Wall stringset.o main.o -o "T17.exe"
	g++ "T18.cpp" -Wall stringset.o main.o -o "T18.exe"
	g++ "T21.cpp" -Wall stringset.o main.o -o "T21.exe"
	g++ "T22.cpp" -Wall stringset.o main.o -o "T22.exe"
	g++ "T23.cpp" -Wall stringset.o main.o -o "T23.exe"

run:
	.\T1.exe
	.\T2.exe
	.\T3.exe
	.\T4.exe
	.\T5.exe
	.\T6.exe
	.\T7.exe
	.\T8.exe
	.\T9.exe
	.\T16.exe
	.\T17.exe
	.\T18.exe
	.\T21.exe
	.\T22.exe
	.\T23.exe

clean:
	del *.exe
	del *.o

remake:
	g++ makemakefile.cpp -o "remake.exe" -Wall
	.\remake.exe
	del remake.exe