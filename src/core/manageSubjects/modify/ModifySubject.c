#include <stdio.h>

#include "../../../database/Database.h"
#include "../../../database/subjectsRepository/UpdateSubjectData.h"

void ModifySubject(Database database) {
  int code;

  printf("\nIngresa el codigo de la materia que deseas modificar: ");
  scanf("%d", &code);

  Subject *subject = database.subjects.findByCode(code);

  if (subject == NULL) {
    printf("\n La materia no existe! \n");

    return;
  }

  int option;

  printf("\n¿Que deseas modificar?\n");
  printf("1. Nombre\n");
  printf("2. Cancelar y salir\n");
  printf("Selecciona una opcion: ");
  scanf("%d", &option);

  UpdateSubjectData data;

  data.name = subject->name;

  switch (option) {
    case 1:
      char name[50];

      printf("\nIngresa el nuevo nombre: ");
      scanf("%49s", name);

      data.name = name;

      break;
    case 2:
      return;
    default:
      printf("\nOpcion no valida, no se realizaron cambios.\n");

      return;
  }

  database.subjects.updateByCode(code, &data);

  printf("\n Materia actualizado!\n");
  printf("--------------------------------\n");
}
