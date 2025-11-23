#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
  char name[50];
  char firstLastName[50];
  char secondLastName[50];
  int code;
  char major[20];
  char *subjects;
} Student;

#endif
