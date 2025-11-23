#ifndef STUDENTS_REPOSITORY_H
#define STUDENTS_REPOSITORY_H

#include "../../core/Student.h"

#include "./CreateStudentData.h"
#include "./StudentList.h"

typedef struct {
  Student (*create)(const CreateStudentData *data);
  StudentList (*findAll)();
} StudentsRepository;

#endif
