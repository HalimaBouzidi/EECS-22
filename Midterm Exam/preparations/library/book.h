#ifndef BOOK_H
#define BOOK_H

#define MAX_TITLE_LENGTH 100
#define MAX_AUTHOR_LENGTH 100

// Structure to represent a book
typedef struct {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
} Book;

// Function prototypes for book operations
void PrintBook(const Book *book);

#endif