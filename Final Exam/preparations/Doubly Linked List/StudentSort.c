/* StudentSort.c: sorting student records (by various criteria) */

#include "StudentSort.h"
#include <stdlib.h> 
#include <stdio.h> 
#include <string.h> 
#include <assert.h>

/* Compare students by ID */
int CompareStudentID(STUDENT *s1, STUDENT *s2)
{
    assert(s1); // Ensure s1 is not NULL
    assert(s2); // Ensure s2 is not NULL
    return (s1->ID - s2->ID); // Return difference in IDs for sorting
} /* end of CompareStudentID */

/* Compare students by name */
int CompareStudentName(STUDENT *s1, STUDENT *s2)
{
    assert(s1); // Ensure s1 is not NULL
    assert(s2); // Ensure s2 is not NULL
    return (strcmp(s1->Name, s2->Name)); // Use strcmp() to compare names
} /* end of CompareStudentName */

/* Compare students by grade */
int CompareStudentGrade(STUDENT *s1, STUDENT *s2)
{
    assert(s1); // Ensure s1 is not NULL
    assert(s2); // Ensure s2 is not NULL
    return (s1->Grade - s2->Grade); // Return difference in grades for sorting
} /* end of CompareStudentGrade */

/* Sort a student list (insertion sort) */
SLIST *SortStudentList(SLIST *l, CMP_F *CompareFct)
{
    SLIST *l2 = NULL; // Create a new sorted list
    STUDENT *s = NULL; // Temporary pointer for students
    assert(l); // Ensure list is not NULL
    assert(CompareFct); // Ensure comparison function is not NULL

    l2 = NewStudentList(); // Create an empty student list

    while ((s = RemoveFirstStudent(l))) // Remove students one by one
    { 
        InsertStudent(l2, s, CompareFct); // Insert into the sorted list
    }

    assert(l->Length == 0); // Ensure original list is empty
    DeleteStudentList(l); // Delete the old unsorted list

    return (l2); // Return the sorted list
} /* end of SortStudentList */

/* Insert a student into a sorted list */
void InsertStudent(SLIST *l, STUDENT *s, CMP_F *CompareFct)
{
    SENTRY *prev = NULL;
    SENTRY *current = NULL;
    
    assert(l); // Ensure list is not NULL
    assert(s); // Ensure student is not NULL
    assert(CompareFct); // Ensure comparison function is not NULL

    // Special case: empty list or new student should be at the beginning
    if (l->First == NULL || CompareFct(l->First->Student, s) > 0) {
        PrependStudent(l, s);
        return;
    }
    
    // Find the position to insert
    prev = l->First;
    current = prev->Next;
    
    while (current != NULL && CompareFct(current->Student, s) <= 0) {
        prev = current;
        current = current->Next;
    }
    
    // Insert after prev
    InsertStudentAfter(prev, s);
} /* end of InsertStudent */

/* Find a student by ID in a sorted list */ 
STUDENT *FindStudentID(SLIST *l, int ID)
{
    SENTRY *e;
    assert(l); // Ensure list is not NULL

    e = l->First; // Start from the first entry

    while (e)
    { 
        if (e->Student->ID == ID) // If the student ID matches, return the student
        { 
            return (e->Student);
        }
    
        if (e->Student->ID > ID) // If the ID is greater, the student is not in the list
        { 
            break;
        }
    
        e = e->Next; // Move to the next student
    }
    return (NULL); // Student not found
} /* end of FindStudentID */

/* Find a student by name in a sorted list */ 
STUDENT *FindStudentName(SLIST *l, char *Name)
{
    SENTRY *e;
    int CompVal;
    assert(l); // Ensure list is not NULL
    assert(Name); // Ensure name is not NULL

    e = l->First; // Start from the first entry

    while (e)
    { 
        CompVal = strcmp(e->Student->Name, Name); // Compare student names
        if (CompVal == 0) // If the names match, return the student
        { 
            return (e->Student);
        }
        if (CompVal > 0) // If the name is greater, the student is not in the list
        { 
            break;
        }
        e = e->Next; // Move to the next student
    }

    return (NULL); // Student not found
} /* end of FindStudentName */

#ifdef MAIN

#include <stdio.h>

int main(void)
{
    SLIST *l = NULL;
    l = NewStudentList(); // Create a new student list

    // Add students to the list
    AppendStudent(l, NewStudent(1001, "Jane Doe", 'A'));
    AppendStudent(l, NewStudent(1002, "John Doe", 'C'));
    AppendStudent(l, NewStudent(1003, "Jim Doe", 'B'));
    AppendStudent(l, NewStudent(1010, "Jane Doe", 'B'));
    AppendStudent(l, NewStudent(1009, "Z End", 'A'));
    AppendStudent(l, NewStudent(1008, "Alice A", 'A'));
    AppendStudent(l, NewStudent(1007, "Bob B", 'B'));
    AppendStudent(l, NewStudent(1006, "Carl C", 'C'));
    AppendStudent(l, NewStudent(1005, "Dave D", 'D'));
    AppendStudent(l, NewStudent(1004, "Eve E", 'F'));

    printf("1. Initial unsorted student list:\n");
    PrintStudentList(l);

    // Sort by name and print
    printf("2. Student list sorted by name:\n");
    l = SortStudentList(l, CompareStudentName);
    PrintStudentList(l);

    // Ensure "John Doe" is found and "No Body" is not found
    assert(FindStudentName(l, "John Doe") != NULL);
    assert(FindStudentName(l, "No Body") == NULL);

    // Sort by ID and print
    printf("3. Student list sorted by ID:\n");
    l = SortStudentList(l, CompareStudentID);
    PrintStudentList(l);

    // Ensure ID 1005 is found and 1999 is not found
    assert(FindStudentID(l, 1005) != NULL);
    assert(FindStudentID(l, 1999) == NULL);

    // Sort by grade and print
    printf("4. Student list sorted by grade:\n");
    l = SortStudentList(l, CompareStudentGrade);
    PrintStudentList(l);

    // Clean up the list
    DeleteStudentList(l);
    l = NULL;

    return 0;
} /* end of main */ 

#endif /* MAIN */
/* EOF */
