#include <stdio.h>

#include "../../../database/Database.h"
#include "../../../database/studentsRepository/StudentList.h"

void GetStudents(Database database) {
  StudentList studentList = database.students.findAll();

  for (int i = 0; i < studentList.count; i++) {
    Student *students = studentList.items;

    printf("Code: %d - Nombre: %s -  Nombre paterno: %s - Nombre materno: %s - Carrera: %s\n",
      students[i].code,
      students[i].name,
      students[i].firstLastName,
      students[i].secondLastName,
      students[i].major
    );
  }
}
