#ifndef DATABASE_H
#define DATABASE_H

#include "./studentsRepository/StudentsRepository.h"
#include "./professorsRepository/ProfessorsRepository.h"

typedef struct {
  StudentsRepository students;
  ProfessorsRepository professors;
} Database;

#endif
