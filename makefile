main: main.o operators.o
	g++ -o output main.o operators.o

main.o: main.cpp operators.h
	g++ -c main.cpp -o main.o

operators.o: operators.cpp operators.h
	g++ -c operators.cpp -o operators.o

clean:
	rm -f output main.o operators.o
