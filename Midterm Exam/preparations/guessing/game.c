#include "game.h"
#include <stdlib.h>
#include <time.h>

// Global variables for game state
static int targetNumber;
static int attempts;

// Function to initialize the game
void InitializeGame()
{
    srand(time(NULL)); // Seed the random number generator
    targetNumber = rand() % 100 + 1; // Random number between 1 and 100
    attempts = 0;
}

// Function to make a guess
int MakeGuess(int guess)
{
    attempts++;
    if (guess < targetNumber)
    {
        return -1; // Guess is too low
    }
    else if (guess > targetNumber)
    {
        return 1; // Guess is too high
    }
    else
    {
        return 0; // Guess is correct
    }
}

// Function to get the number of attempts
int GetAttempts()
{
    return attempts;
}