compile:
	g++ doublyLinkedSwap.cpp -c -o "dLS.o" -Wall
	g++ doublyLinkedSwapMain.cpp -o "doublyLinkedSwapMain.exe" -Wall dLS.o
	g++ T1.cpp -o "T1.exe" dLS.o -Wall
	g++ T2.cpp -o "T2.exe" dLS.o -Wall
	g++ T4.cpp -o "T4.exe" dLS.o -Wall
	g++ T6.cpp -o "T6.exe" dLS.o -Wall

run:
	.\doublyLinkedSwapMain.exe
	.\T1.exe
	.\T2.exe
	.\T4.exe
	.\T6.exe

clean:
	del *.o
	del *.exe