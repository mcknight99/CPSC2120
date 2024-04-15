compile:
	g++ minHeap.cpp -c -o "minHeap.o" -Wall
	g++ "T1.cpp" -Wall -o "T1.exe" minHeap.o
	g++ "T3.cpp" -Wall -o "T3.exe" minHeap.o
	g++ "T6.cpp" -Wall -o "T6.exe" minHeap.o
	g++ "T7.cpp" -Wall -o "T7.exe" minHeap.o
	g++ "T8.cpp" -Wall -o "T8.exe" minHeap.o
	g++ "T10.cpp" -Wall -o "T10.exe" minHeap.o

run:
	.\T1.exe
	.\T3.exe
	.\T6.exe
	.\T7.exe
	.\T8.exe
	.\T10.exe

clean:
	del *.exe
	del *.o

remake:
	g++ makemakefile.cpp -o "remake.exe" -Wall
	.\remake.exe
	del remake.exe
