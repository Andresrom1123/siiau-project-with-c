#ifndef STUDENTS_REPOSITORY_H
#define STUDENTS_REPOSITORY_H

#include "../../core/Student.h"
#include "./CreateStudentData.h"
#include "./StudentList.h"

typedef struct {
  void (*assignSubject)(const int studentCode, const int subjectCode);
  Student (*create)(const CreateStudentData *data);
  StudentList (*findAll)(const void *database);
  Student* (*findByCode)(const int code, const void *database);
} StudentsRepository;

#endif
