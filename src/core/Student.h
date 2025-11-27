#ifndef STUDENT_H
#define STUDENT_H

#include "./Subject.h"
#include "./SubjectList.h"

typedef struct {
  char name[50];
  char firstLastName[50];
  char secondLastName[50];
  int code;
  char major[20];
  SubjectList *subjects;
} Student;

#endif
