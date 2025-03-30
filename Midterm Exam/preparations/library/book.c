#include "book.h"
#include <stdio.h>

// Function to print book details
void PrintBook(const Book *book)
{
    printf("ID: %d, Title: %s, Author: %s\n", book->id, book->title, book->author);
}