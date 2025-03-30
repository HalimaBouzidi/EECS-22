all: prime_program

prime_program: main.o prime.o
	gcc -Wall -g -std=c11 -o prime_program main.o prime.o

main.o: main.c prime.h
	gcc -Wall -g -std=c11 -c main.c

prime.o: prime.c prime.h
	gcc -Wall -g -std=c11 -c prime.c

clean:
	rm -f *.o prime_program