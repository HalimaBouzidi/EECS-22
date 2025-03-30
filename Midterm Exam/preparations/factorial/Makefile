all: factorial_program

factorial_program: main.o factorial.o
	gcc -Wall -g -std=c11 -o factorial_program main.o factorial.o

main.o: main.c factorial.h
	gcc -Wall -g -std=c11 -c main.c

factorial.o: factorial.c factorial.h
	gcc -Wall -g -std=c11 -c factorial.c

clean:
	rm -f *.o factorial_program