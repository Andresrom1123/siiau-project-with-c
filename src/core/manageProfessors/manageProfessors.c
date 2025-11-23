#include <stdio.h>

#include "../../database/Database.h"
#include "./create/CreateProfessor.h"

int manageProfessors(Database database) {
  int option;

  printf("Modulo de professors");
  printf("\n 1. Agregar professor");
  printf("\n 2. Consultar lista de professors");
  printf("\n 3. Buscar un professor");
  printf("\n 4. Modificar un professor");
  printf("\n 5. Eliminar un professor");
  printf("\n 6. Regresar al menu principal");
  printf("\n 7. Guardar y salir");
  printf("\n Que opcion deseas elegir: ");

  scanf("%d", &option);

  switch (option) {
    case 1:
      CreateProfessor(database);

      break;
    case 2:
      // TODO: Implement GetProfessors function (RAFA)
      printf("Consultar lista de professors");

      break;
    case 3:
      printf("Buscar un professor");

      break;
    case 4:
      printf("Modificar un professor");

      break;
    case 5:
      printf("Eliminar un professor");

      break;
    case 6:
      printf("Regresar al menu principal");

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
