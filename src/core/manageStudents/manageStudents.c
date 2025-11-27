#include <stdio.h>

#include "../../database/Database.h"

#include "./assignSubject/AssignSubject.h"
#include "./create/CreateStudent.h"
#include "./get/GetStudents.h"

int manageStudents(Database database) {
  int option;

  printf("Modulo de alumnos:");
  printf("\n 1. Agregar alumno");
  printf("\n 2. Consultar lista de alumnos");
  printf("\n 3. Buscar un alumno");
  printf("\n 4. Modificar un alumno");
  printf("\n 5. Eliminar un alumno");
  printf("\n 6. Asignar una materia a un estudiante");
  printf("\n 7. Regresar al menu principal");
  printf("\n 8. Guardar y salir");
  printf("\n Que opcion deseas elegir: ");

  scanf("%d", &option);

  switch (option) {
    case 1:
      CreateStudent(database);

      break;
    case 2:
      GetStudents(database);

      break;
    case 3:
      printf("Buscar un alumno");

      break;
    case 4:
      printf("Modificar un alumno");

      break;
    case 5:
      printf("Eliminar un alumno");

      break;
    case 6:
      AssignSubject(database);

      break;
    case 7:
      printf("Regresar al menu principal");

      break;
    case 8:
      return 0;

      break;
    default:
      printf("Opcion no valida, intenta de nuevo");

      break;
    }

  return 0;
}
