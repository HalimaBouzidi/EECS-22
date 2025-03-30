#include <stdio.h>
#include "library.h"
#include "menu.h"

int main(void)
{
    Book library[MAX_BOOKS];
    int bookCount = 0;
    int choice;

    do
    {
        choice = DisplayMenu();

        switch (choice)
        {
        case 1:
            AddBook(library, &bookCount);
            break;
        case 2:
            SearchBook(library, bookCount);
            break;
        case 3:
            DisplayAllBooks(library, bookCount);
            break;
        case 4:
            printf("Exiting the program. Goodbye!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}