#include <stdio.h>

#include "../../../database/Database.h"

void GetProfessor(Database database) {
  int code;

  printf("\n Ingresa el codigo del profesor: ");
  scanf("%d", &code);

  Professor *professor = database.professors.findByCode(code);

  if (professor == NULL) {
    printf("\n El profesor no existe \n");

    return;
  }

  printf("Code: %d - Nombre: %s - Apellido paterno: %s - Apellido materno: %s - Departamento: %s\n",
    professor->code,
    professor->name,
    professor->firstLastName,
    professor->secondLastName,
    professor->department
  );

  printf("\n--------------------------------\n");
}
