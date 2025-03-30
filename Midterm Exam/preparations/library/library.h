#ifndef LIBRARY_H
#define LIBRARY_H

#include "book.h"

#define MAX_BOOKS 100

// Function prototypes for library operations
void AddBook(Book library[], int *count);
void SearchBook(const Book library[], int count);
void DisplayAllBooks(const Book library[], int count);

#endif