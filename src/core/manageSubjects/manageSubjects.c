#include <stdio.h>

#include "../../database/Database.h"

#include "./create/CreateSubject.h"
#include "./delete/DeleteSubject.h"
#include "./get/GetSubjects.h"
#include "./modify/ModifySubject.h"

int manageSubjects(Database database) {
  int option;

  printf("Modulo de materias:");
  printf("\n 1. Agregar una materia");
  printf("\n 2. Consultar la lista de materias");
  printf("\n 3. Modificar una materia");
  printf("\n 4. Eliminar una materia");
  printf("\n 5. Guardar y salir");
  printf("\n Que opcion deseas elegir: ");

  scanf("%d", &option);

  switch (option) {
    case 1:
      CreateSubject(database);

      break;
    case 2:
      GetSubjects(database);

      break;
    case 3:
      ModifySubject(database);

      break;
    case 4:
      DeleteSubject(database);

      break;
    case 5:
      return 0;

      break;
    default:
      printf("Opcion no valida, intenta de nuevo");

      break;
  }

  return 0;
}
