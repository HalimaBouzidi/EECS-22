/* StudentList.h: header file for lists of student records */

#ifndef STUDENT_LIST_H 
#define STUDENT_LIST_H

#include "Student.h"

typedef struct StudentList SLIST; 

typedef struct StudentEntry SENTRY;

struct StudentList
{ 
   int Length; 
   SENTRY *First; 
   SENTRY *Last;
};

struct StudentEntry
{ 
   SLIST *List;
   SENTRY *Next; 
   STUDENT *Student;
};

/* allocate a new student list */ 
SLIST *NewStudentList(void);

/* delete a student list (and all entries) */ 
void DeleteStudentList(SLIST *l);

/* prepend/append a student at beginning/end of list */ 
void PrependStudent(SLIST *l, STUDENT *s);

void AppendStudent(SLIST *l, STUDENT *s);

/* insert a student after an existing one */ 
void InsertStudentAfter(SENTRY *e, STUDENT *s);

/* remove the first student from the list */ 
STUDENT *RemoveFirstStudent(SLIST *l);

/* print a student list */
void PrintStudentList(SLIST *l);

#endif /* STUDENT_LIST_H */

/* EOF */
