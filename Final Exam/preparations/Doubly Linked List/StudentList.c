/* StudentList.c: maintaining lists of student records */

#include "StudentList.h" 
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <assert.h>

/***********************************************************************************/

/* allocate a new student list */ 
// This Function NewStudentList Allocates and initializes a new student list (`SLIST`).
// It returns a pointer to the newly created `SLIST` structure.
// It exits the program if memory allocation fails.
SLIST *NewStudentList(void)
{	
    SLIST *l;  // Declare a pointer to an SLIST structure
    l = malloc(sizeof(SLIST));  // Allocate memory dynamically for an SLIST structure
    if (!l)  // Check if memory allocation was successful
    { 
        perror("Out of memory! Aborting...");  // Print an error message
        exit(10);  // Terminate the program with exit code 10
    } /* fi */
    // Initialize the SLIST structure
    l->Length = 0;  // Initialize the list length to 0
    l->First = NULL; // Set the First pointer to NULL (empty list)
    l->Last = NULL;  // Set the Last pointer to NULL (empty list)
    return l; // Return the pointer to the newly created list
} /* end of NewStudentList */

/***********************************************************************************/

/* allocate a new student entry */
// The function `NewStudentEntry` is used to create a new `SENTRY` structure,
// allocate memory for it, initialize its members, and return a pointer to it.
static SENTRY *NewStudentEntry(STUDENT *s)  
{	
    SENTRY *e; // Declare a pointer variable `e` of type `SENTRY`
    e = malloc(sizeof(SENTRY)); // Allocate memory dynamically for a `SENTRY` structure
    if (!e)  // Check if memory allocation failed
    { 
        perror("Out of memory! Aborting..."); // Print error message
        exit(10); // Terminate the program with exit code 10
    } /* fi */
    // Initialize the newly allocated `SENTRY` structure
    e->List = NULL;  // Set `List` pointer to NULL
    e->Next = NULL;  // Set `Next` pointer to NULL
    e->Prev = NULL;  // Set `Prev` pointer to NULL
    e->Student = s;  // Assign the passed student pointer to `Student`

    return e; // Return the pointer to the newly created `SENTRY` structure
} /* end of NewStudentEntry */

/***********************************************************************************/

/* delete a new student entry */
// The function `DeleteStudentEntry` is responsible for deleting a `SENTRY` structure 
// while preserving the associated `STUDENT` pointer, which is returned to the caller.
static STUDENT *DeleteStudentEntry(SENTRY *e) 
{	
    STUDENT *s;  // Declare a pointer to store the associated STUDENT
    assert(e);   // Ensure the input pointer `e` is not NULL (runtime check in debug mode)
    s = e->Student;  // Retrieve and store the STUDENT pointer before freeing SENTRY
    free(e);  // Free the allocated memory for the SENTRY structure
    return s; // Return the STUDENT pointer to the caller (ownership is transferred)
} /* end of DeleteStudentEntry */

/***********************************************************************************/
 
/* delete a student list (and all entries) */ 
// Deletes all student entries from a student list (`SLIST`) and frees the list itself.
void DeleteStudentList(SLIST *l) 
{	
    SENTRY *e, *n;  // Declare pointers for traversing and deleting entries
    STUDENT *s;     // Pointer to hold the `STUDENT` before deletion
    assert(l);  // Ensure the input list is not NULL (runtime check in debug mode)
    e = l->First;  // Start with the first entry in the list
    while (e)  // Loop through the list until all entries are deleted
    { 
        n = e->Next;  // Store the next entry before deleting the current one
        s = DeleteStudentEntry(e);  // Delete the current entry and retrieve the associated student
        DeleteStudent(s);  // Delete the associated `STUDENT` structure
        e = n;  // Move to the next entry
    }
    free(l);  // Free the memory allocated for the list itself
} /* end of DeleteStudentList */

/***********************************************************************************/

/* append a student at end of list */ 
// Appends a new student (`STUDENT *s`) to the student list (`SLIST *l`).
void AppendStudent(SLIST *l, STUDENT *s)
{	
    SENTRY *e = NULL; // Pointer to store the new entry
    assert(l); // Ensure the input list is not NULL
    assert(s); // Ensure the input student is not NULL
    e = NewStudentEntry(s); // Allocate and initialize a new `SENTRY` for the student
    if (l->Last) // If the list is not empty
    { 
        e->List = l;        // Set the list reference in the entry
        e->Next = NULL;     // As the last entry, `Next` should be NULL
        e->Prev = l->Last;  // Link to the current last entry
        l->Last->Next = e;  // Update the current last entry to point to the new entry
        l->Last = e;        // Update the last pointer to the new entry
    }
    else // If the list is empty, initialize it with the first student
    { 
        e->List = l;  // Set the list reference in the entry
        e->Next = NULL; 
        e->Prev = NULL; 
        l->First = e;  // Set both first and last pointers to the new entry
        l->Last = e;
    }
    l->Length++; // Increase the list length
} /* end of AppendStudent */

/***********************************************************************************/

/* prepend a student at beginning of list */ 
// Adds a new student (`STUDENT *s`) to the beginning of the student list (`SLIST *l`).
void PrependStudent(SLIST *l, STUDENT *s)
{	
    SENTRY *e = NULL; // Pointer to store the new entry
    assert(l); // Ensure the input list is not NULL
    assert(s); // Ensure the input student is not NULL
    e = NewStudentEntry(s); // Allocate and initialize a new `SENTRY` for the student
    if (l->First) // If the list is not empty
    { 
        e->List = l;         // Set the list reference in the entry
        e->Next = l->First;  // Point the new entry's `Next` to the current first entry
        e->Prev = NULL;      // As the first entry, `Prev` should be NULL
        l->First->Prev = e;  // Update the current first entry's `Prev` pointer
        l->First = e;        // Update the first pointer to the new entry
    } 
    else // If the list is empty, initialize it with the new entry
    { 
        e->List = l;  // Set the list reference in the entry
        e->Next = NULL; 
        e->Prev = NULL; 
        l->First = e;  // Set both first and last pointers to the new entry
        l->Last = e;
    }
    l->Length++; // Increase the list length
} /* end of PrependStudent */

/***********************************************************************************/

/* remove the first student from the list */ 
// Removes and returns the first student (`STUDENT *`) from the student list (`SLIST *l`).
STUDENT *RemoveFirstStudent(SLIST *l)
{	
    SENTRY *e = NULL; // Pointer to store the first entry
    assert(l); // Ensure the input list is not NULL
    if (l->First) // If the list is not empty
    { 
        e = l->First;      // Store the first entry
        l->First = e->Next; // Move the first pointer to the next entry
        if (l->First) // If there is a next entry, update its `Prev` pointer
        {
            l->First->Prev = NULL;
        }
        else // If the list is now empty after removal
        { 
            assert(l->Last == e); // Ensure the last entry was the one being removed
            l->Last = NULL; // Update the last pointer to NULL
        }
        l->Length--; // Decrement the list length
        return DeleteStudentEntry(e); // Delete the entry and return the associated student
    }
    else
    { 
        return NULL; // Return NULL if the list is already empty
    }
} /* end of RemoveFirstStudent */

/***********************************************************************************/

/* remove the last student from the list */
// Removes and returns the last student (`STUDENT *`) from the student list (`SLIST *l`).
STUDENT *RemoveLastStudent(SLIST *l)
{	
    SENTRY *e = NULL; // Pointer to store the last entry
    assert(l); // Ensure the input list is not NULL
    if (l->Last) // If the list is not empty
    { 
        e = l->Last;      // Store the last entry
        l->Last = e->Prev; // Move the last pointer to the previous entry
        if (l->Last) // If there is a previous entry, update its `Next` pointer
        { 
            l->Last->Next = NULL;
        } 
        else // If the list is now empty after removal
        { 
            assert(l->First == e); // Ensure the first entry was the one being removed
            l->First = NULL; // Update the first pointer to NULL
        }
        l->Length--; // Decrement the list length

        return DeleteStudentEntry(e); // Delete the entry and return the associated student
    }
    else
    { 
        return NULL; // Return NULL if the list is already empty
    }
} /* end of RemoveLastStudent */

/***********************************************************************************/

/* insert a student before an existing one */ 
// Inserts a new student (`STUDENT *s`) before an existing entry (`SENTRY *e`) in the student list.
void InsertStudentBefore(SENTRY *e, STUDENT *s)
{
    SENTRY *New;  // Pointer to store the new student entry
    New = NewStudentEntry(s);  // Create a new student entry
    New->List = e->List;  // Assign the list to the new entry
    New->Next = e;  // Set the new entry's `Next` pointer to the existing entry
    New->Prev = e->Prev;  // Set the new entry's `Prev` pointer to the previous entry
    e->Prev = New;  // Update the previous pointer of the existing entry to the new entry
    if (New->Prev) // If there was a previous entry, update its `Next` pointer
    { 
        New->Prev->Next = New;
    }
    else // If the new entry is now the first in the list
    { 
        assert(New->List->First == e); // Ensure the original first entry was `e`
        New->List->First = New; // Update the list's `First` pointer to the new entry
    }
    New->List->Length++; // Increment the list length
} /* end of InsertStudentBefore */

/***********************************************************************************/

/* insert a student after an existing one */ 
// Inserts a new student (`STUDENT *s`) after an existing entry (`SENTRY *e`) in the student list.
void InsertStudentAfter(SENTRY *e, STUDENT *s)
{
    SENTRY *New;  // Pointer to store the new student entry
    New = NewStudentEntry(s);  // Create a new student entry
    New->List = e->List;  // Assign the list to the new entry
    New->Next = e->Next;  // Set the new entry's `Next` pointer to the existing entry's next
    New->Prev = e;  // Set the new entry's `Prev` pointer to the existing entry
    e->Next = New;  // Update the `Next` pointer of the existing entry to point to the new entry
    if (New->Next) // If there is an entry after the new entry, update its `Prev` pointer
    { 
        New->Next->Prev = New;
    }
    else // If the new entry is now the last in the list
    { 
        assert(New->List->Last == e); // Ensure the original last entry was `e`
        New->List->Last = New; // Update the list's `Last` pointer to the new entry
    }
    New->List->Length++; // Increment the list length
} /* end of InsertStudentAfter */

/***********************************************************************************/

/* print a student list */ 
// Prints all students in the student list (`SLIST *l`).
void PrintStudentList(SLIST *l)
{
    SENTRY *e; // Pointer to traverse the list
    assert(l); // Ensure the input list is not NULL
    e = l->First; // Start from the first entry in the list
    while (e) // Loop through the list until the end
    { 
        PrintStudent(e->Student); // Print the student details
        e = e->Next; // Move to the next entry
    } 
} /* end of PrintStudentList */

/***********************************************************************************/

// #ifdef MAIN 
// int main(void)
// {	
//     STUDENT *s = NULL; 
//     SLIST *l = NULL;
//     l = NewStudentList();
//     s = NewStudent(1002, "John Doe", 'C'); AppendStudent(l, s);
//     s = NewStudent(1003, "Jim Doe", 'B'); AppendStudent(l, s);
//     s = NewStudent(1001, "Jane Doe", 'A'); PrependStudent(l, s); PrintStudentList(l);
//     s = RemoveFirstStudent(l); AppendStudent(l, s);
//     s = RemoveLastStudent(l); PrependStudent(l, s); DeleteStudentList(l);
//     l = NULL;
//     return 0;
// } /* end of main */ 
// #endif /* MAIN */


/***********************************************************************************/

#ifdef MAIN 

int main(void)
{
    STUDENT *s = NULL; 
    SLIST *l = NULL; 
    SENTRY *e = NULL;
    l = NewStudentList();
    s = NewStudent(1002, "John Doe", 'C'); 
    AppendStudent(l, s);
    e = l->First;
    assert(e->Student == s);
    s = NewStudent(1003, "Jim Doe", 'B'); 
    InsertStudentAfter(e, s);
    s = NewStudent(1001, "Jane Doe", 'A'); 
    InsertStudentBefore(e, s);
    PrintStudentList(l);
    DeleteStudentList(l); 
    l = NULL;
    return 0;
} /* end of main */ 
#endif /* MAIN */

/* EOF */
/* EOF */