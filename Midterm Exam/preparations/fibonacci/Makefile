all: fibonacci_program

fibonacci_program: main.o fibonacci.o
	gcc -Wall -g -std=c11 -o fibonacci_program main.o fibonacci.o

main.o: main.c fibonacci.h
	gcc -Wall -g -std=c11 -c main.c

fibonacci.o: fibonacci.c fibonacci.h
	gcc -Wall -g -std=c11 -c fibonacci.c

clean:
	rm -f *.o fibonacci_program