all: guessing_game

guessing_game: main.o game.o
	gcc -Wall -g -std=c11 -o guessing_game main.o game.o

main.o: main.c game.h
	gcc -Wall -g -std=c11 -c main.c

game.o: game.c game.h
	gcc -Wall -g -std=c11 -c game.c

clean:
	rm -f *.o guessing_game