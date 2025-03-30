all: library_program

library_program: main.o book.o library.o menu.o
	gcc -Wall -g -std=c11 -o library_program main.o book.o library.o menu.o

main.o: main.c library.h menu.h
	gcc -Wall -g -std=c11 -c main.c

book.o: book.c book.h
	gcc -Wall -g -std=c11 -c book.c

library.o: library.c library.h
	gcc -Wall -g -std=c11 -c library.c

menu.o: menu.c menu.h
	gcc -Wall -g -std=c11 -c menu.c

clean:
	rm -f *.o library_program