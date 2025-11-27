#include <stdio.h>

#include "../../database/Database.h"
#include "./create/CreateProfessor.h"
#include "./get/GetProfessors.h"

#include "./create/CreateProfessor.h"


int manageProfessors(Database database) {
  int option;

  printf("Modulo de professores");
  printf("\n 1. Agregar un profesor");
  printf("\n 2. Consultar lista de profesores");
  printf("\n 3. Buscar un profesor");
  printf("\n 4. Modificar un profesor");
  printf("\n 5. Eliminar un profesor");
  printf("\n 6. Guardar y salir");
  printf("\n Que opcion deseas elegir: ");

  scanf("%d", &option);

  switch (option) {
    case 1:
      CreateProfessor(database);

      break;
    case 2:
      GetProfessors(database);
      
      break;
    case 3:
      // GetProfessor(database);

      break;
    case 4:
      printf("Modificar un professor");

      break;
    case 5:
      printf("Eliminar un professor");

      break;
    case 6:
      return 0;

      break;
    default:
      printf("Opcion no valida, intenta de nuevo");

      break;
    }

  return 0;
}
