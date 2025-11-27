#include <stdio.h>

#include "../../database/Database.h"

#include "./create/CreateSubject.h"

int manageSubjects(Database database) {
  int option;

  printf("Modulo de materias:");
  printf("\n 1. Agregar una materia");
  printf("\n 2. Consultar la lista de materias");
  printf("\n 3. Agregar una materia a un estudiante");
  printf("\n 4. Modificar una materia");
  printf("\n 5. Eliminar una materia");
  printf("\n 6. Regresar al menu principal");
  printf("\n 7. Guardar y salir");
  printf("\n Que opcion deseas elegir: ");

  scanf("%d", &option);

  switch (option) {
    case 1:
      CreateSubject(database);

      break;
    case 2:
      printf("\nConsultar la lista de materias");

      break;
    case 3:
      printf("\nAgregar una materia a un estudiante");

      break;
    case 4:
      printf("\nModificar una materia");

      break;
    case 5:
      printf("\nEliminar una materia");

      break;
    case 6:
      printf("\nRegresar al menu principal");

      break;
    case 7:
      return 0;

      break;
    default:
      printf("Opcion no valida, intenta de nuevo");

      break;
  }

  return 0;
}
