#ifndef PROFESSOR_LIST_H
#define PROFESSOR_LIST_H

#include "../../core/Professor.h"

typedef struct {
  Professor* items;
  int count;
} ProfessorList;

#endif

