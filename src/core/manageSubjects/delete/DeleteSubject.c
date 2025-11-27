#include <stdio.h>

#include "../../../database/Database.h"

void DeleteSubject(Database database) {
  int code;

  printf("\n Ingresa el codigo de la materia que deseas borrar: ");
  scanf("%d", &code);

  Subject *student = database.subjects.findByCode(code);

  if (student == NULL) {
    printf("\n La materia no existe! \n");

    return;
  }

  database.subjects.deleteByCode(code);

  printf("\n La materia se ha borrado correctamente! \n");
}