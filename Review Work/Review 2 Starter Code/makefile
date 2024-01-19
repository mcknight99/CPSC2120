compile:
	g++ review.cpp -c -Wall 
# There's probably a better way to do this with makefiles but I'm not super fluent in makefiles yet
	g++ T1.cpp review.o -o "T1.exe" -Wall
	g++ T2.cpp review.o -o "T2.exe" -Wall
	g++ T3.cpp review.o -o "T3.exe" -Wall
	g++ T4.cpp review.o -o "T4.exe" -Wall
	g++ T5.cpp review.o -o "T5.exe" -Wall
	g++ T6.cpp review.o -o "T6.exe" -Wall

run:
	.\T1.exe
	.\T2.exe
	.\T3.exe
	.\T4.exe
	.\T5.exe
	.\T6.exe

clean:
	del *.o
	del *.exe