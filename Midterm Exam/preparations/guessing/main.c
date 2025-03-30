#include <stdio.h>
#include "game.h"

int main(void)
{
    int guess, result;

    // Initialize the game
    InitializeGame();

    printf("Welcome to the Number Guessing Game!\n");
    printf("I have chosen a number between 1 and 100. Can you guess it?\n");

    do
    {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        result = MakeGuess(guess);

        if (result == -1)
        {
            printf("Too low! Try again.\n");
        }
        else if (result == 1)
        {
            printf("Too high! Try again.\n");
        }
        else
        {
            printf("Congratulations! You guessed the number in %d attempts.\n", GetAttempts());
        }
    } while (result != 0);

    return 0;
}