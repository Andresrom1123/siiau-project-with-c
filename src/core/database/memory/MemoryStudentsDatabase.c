#include <stdio.h>
#include <string.h>

#include "../../Student.h"

#include "../../../database/studentsRepository/CreateStudentData.h"
#include "../../../database/studentsRepository/StudentsRepository.h"

Student createStudent(const CreateStudentData *data) {
  Student student;

  strcpy(student.id, "123");
  strcpy(student.name, data->name);
  strcpy(student.firstLastName, data->firstLastName);
  strcpy(student.secondLastName, data->secondLastName);
  strcpy(student.major, data->major);

  student.code = data->code;

  return student;
}

StudentsRepository newMemoryStudentsDatabase() {
  StudentsRepository repo;

  repo.create = &createStudent;

  return repo;
}
