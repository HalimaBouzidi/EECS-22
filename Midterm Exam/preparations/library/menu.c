#include "menu.h"
#include <stdio.h>

// Function to display the menu and get user choice
int DisplayMenu()
{
    int choice;
    printf("\nLibrary Management System\n");
    printf("1. Add a Book\n");
    printf("2. Search for a Book\n");
    printf("3. Display All Books\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);
    return choice;
}