#include <stdio.h>

#include "../../../database/Database.h"

void GetStudent(Database database) {
  int code;

  printf("\n Ingresa el codigo del estudiante: ");
  scanf("%d", &code);

  Student *student = database.students.findByCode(code);

  if (student == NULL) {
    printf("\n El estudiante no existe \n");

    return;
  }

  printf("Code: %d - Nombre: %s - Apellido paterno: %s - Apellido materno: %s - Carrera: %s\n",
    student->code,
    student->name,
    student->firstLastName,
    student->secondLastName,
    student->major
  );

  if (student->subjects == NULL || student->subjects->count == 0) {
    printf("\n El estudiante no tiene materias \n");

    return;
  }

  printf("\n Materias asignadas:\n");

  for (int j = 0; j < student->subjects->count; j++) {
    Subject subject = student->subjects->items[j];

    printf("  - Code: %d  |  Nombre: %s\n",
      subject.code,
      subject.name
    );
  }

  printf("\n--------------------------------\n");
}
