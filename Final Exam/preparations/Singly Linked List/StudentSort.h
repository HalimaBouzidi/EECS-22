/* StudentSort.h: header file for sorted student records​ */

#ifndef STUDENT_SORT_H 
#define STUDENT_SORT_H

#include "Student.h" 
#include "StudentList.h"

typedef int CMP_F(STUDENT *s1, STUDENT *s2);

/* compare students by ID */
int CompareStudentID(STUDENT *s1, STUDENT *s2);

/* compare students by name */
int CompareStudentName(STUDENT *s1, STUDENT *s2);

/* compare students by grade */
int CompareStudentGrade(STUDENT *s1, STUDENT *s2);

/* sort a student list */
SLIST *SortStudentList(SLIST *l, CMP_F *CompareFct);

/* insert a student into a sorted list */
void InsertStudent(SLIST *l, STUDENT *s, CMP_F *CompareFct);

/* find a student by ID in a sorted list */ 
STUDENT *FindStudentID(SLIST *l, int ID);

/* find a student by name in a sorted list */ 
STUDENT *FindStudentName(SLIST *l, char *Name);

#endif /* STUDENT_SORT_H */

/* EOF */
