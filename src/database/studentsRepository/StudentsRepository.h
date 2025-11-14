#ifndef STUDENTS_REPOSITORY_H
#define STUDENTS_REPOSITORY_H

#include "../../core/Student.h"

#include "./CreateStudentData.h"

typedef struct {
  Student (*create)(const CreateStudentData *data);
} StudentsRepository;

#endif
