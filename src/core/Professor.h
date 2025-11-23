#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct {
  int code;
  char name[50];
  char firstLastName[50];
  char secondLastName[50];
  char department[50];
  char *subject;
} Professor;

#endif
