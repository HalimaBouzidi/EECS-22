# Makefile: Student Records

# Macro definitions
CC = gcc

DEBUG = -g 
#DEBUG = -O2

CFLAGS = -Wall -std=c11 $(DEBUG) -c
LFLAGS = -Wall -std=c11 $(DEBUG)

MAIN = -DMAIN

# Dummy targets
all: Student StudentList StudentSort

test: all
	valgrind ./Student
	valgrind ./StudentList
	valgrind ./StudentSort

clean:
	rm -f *.o
	rm -f Student StudentList StudentSort

# Compilation rules
Student.o: Student.c Student.h
	$(CC) $(CFLAGS) Student.c -o Student.o

Student: Student.c Student.h
	$(CC) $(MAIN) $(LFLAGS) Student.c -o Student

StudentList.o: StudentList.c StudentList.h Student.h
	$(CC) $(CFLAGS) StudentList.c -o StudentList.o

StudentList: StudentList.c StudentList.h Student.h Student.o
	$(CC) $(MAIN) $(LFLAGS) StudentList.c Student.o -o StudentList

StudentSort.o: StudentSort.c StudentSort.h StudentList.h Student.h
	$(CC) $(CFLAGS) StudentSort.c -o StudentSort.o

StudentSort: StudentSort.c StudentSort.h StudentList.h Student.h StudentList.o Student.o
	$(CC) $(MAIN) $(LFLAGS) StudentSort.c StudentList.o Student.o -o StudentSort

# EOF
