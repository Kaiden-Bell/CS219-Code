output: main.o operators.o
	g++ -o operators.o 
main.o: main.cpp
	g++ -o main.o
operators.o: operators.cpp operators.h
	g++ -o operators.o
clean:
	rm -f output