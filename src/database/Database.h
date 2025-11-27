#ifndef DATABASE_H
#define DATABASE_H

#include "./professorsRepository/ProfessorsRepository.h"
#include "./studentsRepository/StudentsRepository.h"
#include "./subjectsRepository/SubjectsRepository.h"

typedef struct {
  ProfessorsRepository professors;
  StudentsRepository students;
  SubjectsRepository subjects;
} Database;

#endif
