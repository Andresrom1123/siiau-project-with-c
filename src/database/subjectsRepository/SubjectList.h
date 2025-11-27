#ifndef SUBJECT_LIST_H
#define SUBJECT_LIST_H

#include "../../core/Subject.h"

typedef struct {
  Subject* items;
  int count;
} SubjectList;

#endif
