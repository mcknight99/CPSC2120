compile:
	g++ review.cpp -c -Wall 

t1:
	g++ T1.cpp review.o -o "T1.exe" -Wall
	.\T1.exe

t2:
	g++ T2.cpp review.o -o "T2.exe" -Wall
	.\T2.exe

t3:
	g++ T3.cpp review.o -o "T3.exe" -Wall
	.\T3.exe

t4:
	g++ T4.cpp review.o -o "T4.exe" -Wall
	.\T4.exe

t5:
	g++ T5.cpp review.o -o "T5.exe" -Wall
	.\T5.exe

t6:
	g++ T6.cpp review.o -o "T6.exe" -Wall
	.\T6.exe

run:
	make compile
	make t1
	make t2
	make t3
	make t4
	make t5
	make t6

clean:
	del *.o
	del *.exe