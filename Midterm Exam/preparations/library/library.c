#include "library.h"
#include <stdio.h>
#include <string.h>

// Function to add a book to the library
void AddBook(Book library[], int *count)
{
    if (*count >= MAX_BOOKS)
    {
        printf("Library is full. Cannot add more books.\n");
        return;
    }

    Book newBook;
    newBook.id = *count + 1;

    printf("Enter book title: ");
    scanf(" %[^\n]", newBook.title);

    printf("Enter book author: ");
    scanf(" %[^\n]", newBook.author);

    library[*count] = newBook;
    (*count)++;

    printf("Book added successfully!\n");
}

// Function to search for a book by title
void SearchBook(const Book library[], int count)
{
    char searchTitle[MAX_TITLE_LENGTH];
    printf("Enter the title to search: ");
    scanf(" %[^\n]", searchTitle);

    int found = 0;
    for (int i = 0; i < count; i++)
    {
        if (strcmp(library[i].title, searchTitle) == 0)
        {
            PrintBook(&library[i]);
            found = 1;
        }
    }

    if (!found)
    {
        printf("No book found with the title: %s\n", searchTitle);
    }
}

// Function to display all books in the library
void DisplayAllBooks(const Book library[], int count)
{
    if (count == 0)
    {
        printf("No books in the library.\n");
        return;
    }

    printf("Books in the library:\n");
    for (int i = 0; i < count; i++)
    {
        PrintBook(&library[i]);
    }
}