all: reverse_program

reverse_program: main.o reverse.o
	gcc -Wall -g -std=c11 -o reverse_program main.o reverse.o

main.o: main.c reverse.h
	gcc -Wall -g -std=c11 -c main.c

reverse.o: reverse.c reverse.h
	gcc -Wall -g -std=c11 -c reverse.c

clean:
	rm -f *.o reverse_program