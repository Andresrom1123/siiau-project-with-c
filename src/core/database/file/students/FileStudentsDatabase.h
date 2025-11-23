#ifndef MEMORY_STUDENTS_DATABASE_H
#define MEMORY_STUDENTS_DATABASE_H

#include "../../../../database/studentsRepository/CreateStudentData.h"
#include "../../../../database/studentsRepository/StudentsRepository.h"
#include "../../../Student.h"

Student createStudent(const CreateStudentData *data);
StudentsRepository newFileStudentsDatabase();

#endif
