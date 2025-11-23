#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H

#include "../../core/Student.h"

typedef struct {
  Student* items;
  int count;
} StudentList;

#endif
