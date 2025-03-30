/* Student.c: maintaining student records */

#include "Student.h" 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <assert.h>

/* allocate a new student record */
// Creates a new student (`STUDENT *`) and initializes it with provided values.
STUDENT *NewStudent(int ID, char *Name, char Grade)
{	
    STUDENT *s; // Pointer to store the new student
    s = malloc(sizeof(STUDENT)); // Allocate memory dynamically for a `STUDENT`
    if (!s) // Check if memory allocation failed
    { 
        perror("Out of memory! Aborting..."); // Print error message
        exit(10); // Terminate the program with exit code 10
    } /* fi */ 
    s->ID = ID; // Assign student ID
    strncpy(s->Name, Name, SLEN); // Copy the name with a maximum length of `SLEN`
    s->Name[SLEN] = '\0'; // Ensure null termination to prevent overflow
    s->Grade = Grade; // Assign student grade
    return s; // Return the pointer to the newly created student
} /* end of NewStudent */

/***********************************************************************************/

/* delete a student record */ 
// Frees the memory allocated for a student (`STUDENT *s`).
void DeleteStudent(STUDENT *s)
{
    assert(s); // Ensure the input student pointer is not NULL
    free(s);   // Free the memory allocated for the student structure
} /* end of DeleteStudent */

/***********************************************************************************/

/* print a student record */ 
// Prints the details of a student (`STUDENT *s`).
void PrintStudent(STUDENT *s)
{
    assert(s); // Ensure the input student pointer is not NULL
    printf("Student ID:   %d\n", s->ID);    // Print student ID
    printf("Student Name: %s\n", s->Name);  // Print student name
    printf("Student Grade: %c\n", s->Grade); // Print student grade
} /* end of PrintStudent */

/***********************************************************************************/

/* test the student record functions */ 
#ifdef MAIN 
int main(void)
{	
    STUDENT *s1 = NULL, *s2 = NULL;
    printf("Creating 2 student records...\n"); 
    s1 = NewStudent(1001, "Jane Doe", 'A'); 
    s2 = NewStudent(1002, "John Doe", 'C');
    printf("Printing the student records...\n"); 
    PrintStudent(s1);
    PrintStudent(s2);
    printf("Deleting the student records...\n"); 
    DeleteStudent(s1);
    s1 = NULL;
    DeleteStudent(s2); 
    s2 = NULL;
    printf("Done.\n"); 
    return 0;
} /* end of main */ 
#endif /* MAIN */

/* EOF */
