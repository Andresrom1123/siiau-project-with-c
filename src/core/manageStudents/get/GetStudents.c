#include <stdio.h>

#include "../../../database/Database.h"
#include "../../../database/studentsRepository/StudentList.h"

void GetStudents(Database database) {
  StudentList studentList = database.students.findAll();

  for (int i = 0; i < studentList.count; i++) {
    Student *students = studentList.items;

    printf("Code: %d - Nombre: %s - Apellido paterno: %s - Apellido materno: %s - Carrera: %s\n",
      students[i].code,
      students[i].name,
      students[i].firstLastName,
      students[i].secondLastName,
      students[i].major
    );

    if (students[i].subjects == NULL || students[i].subjects->count == 0) {
      printf("\n El alumno no tiene materias \n");

      continue;
    }

    printf("\n Materias asignadas:\n");

    for (int j = 0; j < students[i].subjects->count; j++) {
      Subject subject = students[i].subjects->items[j];

      printf("  - Code: %d  |  Nombre: %s\n",
        subject.code,
        subject.name
      );
    }

    printf("\n--------------------------------\n");
  }
}
