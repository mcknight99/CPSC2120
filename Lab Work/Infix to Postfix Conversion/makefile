compile:
	g++ infixToPostfix.cpp -Wall -c -o "iTPL.o"
	g++ infixToPostfixMain.cpp -Wall -o "infixToPostfixMain.exe" iTPL.o
	g++ T1.cpp -Wall -o "T1.exe" iTPL.o
	g++ T2.cpp -Wall -o "T2.exe" iTPL.o
	g++ T3.cpp -Wall -o "T3.exe" iTPL.o
	g++ T4.cpp -Wall -o "T4.exe" iTPL.o
	g++ T5.cpp -Wall -o "T5.exe" iTPL.o
	g++ T6.cpp -Wall -o "T6.exe" iTPL.o
	g++ T9.cpp -Wall -o "T9.exe" iTPL.o
	g++ T16.cpp -Wall -o "T16.exe" iTPL.o
	g++ T17.cpp -Wall -o "T17.exe" iTPL.o
	g++ T18.cpp -Wall -o "T18.exe" iTPL.o
	g++ T19.cpp -Wall -o "T19.exe" iTPL.o

run:
	.\infixToPostfixMain.exe
	.\T1.exe
	.\T2.exe
	.\T3.exe
	.\T4.exe
	.\T5.exe
	.\T6.exe
	.\T9.exe
	.\T16.exe
	.\T17.exe
	.\T18.exe
	.\T19.exe

clean:
	del *.o
	del *.exe