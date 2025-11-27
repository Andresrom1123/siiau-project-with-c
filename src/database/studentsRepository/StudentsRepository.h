#ifndef STUDENTS_REPOSITORY_H
#define STUDENTS_REPOSITORY_H

#include "../../core/Student.h"
#include "./CreateStudentData.h"
#include "./UpdateStudentData.h"
#include "./StudentList.h"

typedef struct {
  void (*assignSubject)(const int studentCode, const int subjectCode);
  Student (*create)(const CreateStudentData *data);
  StudentList (*findAll)();
  Student* (*findByCode)(const int code);
  void (*updateByCode)(const int code, const UpdateStudentData *data);
} StudentsRepository;

#endif
