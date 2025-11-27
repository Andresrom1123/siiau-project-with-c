#include <stdio.h>

#include "../../../database/Database.h"

void DeleteProfessor(Database database) {
  int code;

  printf("\n Ingresa el codigo del profesor que deseas borrar: ");
  scanf("%d", &code);

  Professor *professor = database.professors.findByCode(code);

  if (professor == NULL) {
    printf("\n El profesor no existe! \n");

    return;
  }

  database.professors.deleteByCode(code);

  printf("\n El profesor se ha borrado correctamente! \n");
}
