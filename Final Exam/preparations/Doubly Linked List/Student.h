/* Student.h: header file for student records */

#ifndef STUDENT_H 
#define STUDENT_H

#define SLEN 40 

struct Student
{ 
    int ID;
    char Name[SLEN+1]; 
    char Grade;
};

typedef struct Student STUDENT;

/* allocate a new student record */

STUDENT *NewStudent(int ID, char *Name, char Grade);

/* delete a student record */ 

void DeleteStudent(STUDENT *s);

/* print a student record */ 

void PrintStudent(STUDENT *s);

#endif /* STUDENT_H */