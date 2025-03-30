all: SquareRoot

SquareRoot: sqrt.o main.o
			gcc sqrt.o main.o -o SquareRoot

sqrt.o:     sqrt.c sqrt.h
			gcc -c -Wall -std=c11 sqrt.c -o sqrt.o

main.o:   main.c sqrt.h
		  gcc -c -Wall -std=c11 main.c -o main.o