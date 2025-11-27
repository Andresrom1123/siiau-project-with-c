#include <stdio.h>

#include "./core/database/file/FileDatabase.h"
#include "./core/manageProfessors/manageProfessors.h"
#include "./core/manageStudents/manageStudents.h"
#include "./core/manageSubjects/manageSubjects.h"

int main() {
  int option;

  Database database = newFileDatabase();

  printf("Sistema gestion academica MI UNI");
  printf("\n 1. Gestion de alumnos");
  printf("\n 2. Gestion de profesores");
  printf("\n 3. Gestion de materias");
  printf("\n 4. Guardar y salir");
  printf("\n Que opcion deseas elegir: ");

  scanf("%d", &option);

  switch (option) {
    case 1:
      manageStudents(database);

      break;
    case 2:
      manageProfessors(database);

      break;
    case 3:
      manageSubjects(database);

      break;
    case 4:
      return 0;

      break;
    default:
      printf("Opcion no valida, intenta de nuevo");

      break;
  }

  return 0;
}
