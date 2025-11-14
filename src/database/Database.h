#ifndef DATABASE_H
#define DATABASE_H

#include "./studentsRepository/StudentsRepository.h"

typedef struct {
  StudentsRepository students;
} Database;

#endif
