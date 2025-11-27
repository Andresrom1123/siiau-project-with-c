#include <stdio.h>

#include "../../../database/Database.h"

void DeleteStudent(Database database) {
  int code;

  printf("\n Ingresa el codigo del estudiante que deseas borrar: ");
  scanf("%d", &code);

  Student *student = database.students.findByCode(code);

  if (student == NULL) {
    printf("\n El estudiante no existe! \n");

    return;
  }

  database.students.deleteByCode(code);

  printf("\n El estudiante se ha borrado correctamente! \n");
}
