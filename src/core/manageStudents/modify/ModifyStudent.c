#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../database/Database.h"
#include "../../../core/Student.h"
#include "../../../database/studentsRepository/UpdateStudentData.h"

void ModifyStudent(Database database) {
  int code;

  printf("\nIngresa el codigo del estudiante que deseas modificar: ");
  scanf("%d", &code);

  Student *student = database.students.findByCode(code);

  if (student == NULL) {
    printf("\n El estudiante no existe! \n");

    return;
  }

  int option;

  printf("\n¿Que deseas modificar?\n");
  printf("1. Nombre\n");
  printf("2. Apellido paterno\n");
  printf("3. Apellido materno\n");
  printf("4. Carrera\n");
  printf("5. Cancelar y salir\n");
  printf("Selecciona una opcion: ");
  scanf("%d", &option);

  UpdateStudentData data;

  data.name = student->name;
  data.firstLastName = student->firstLastName;
  data.secondLastName = student->secondLastName;
  data.major = student->major;

  switch (option) {
    case 1:
      char name[50];

      printf("\nIngresa el nuevo nombre: ");
      scanf("%49s", name);

      data.name = name;

      break;
    case 2:
      char firstLastName[50];

      printf("\nIngresa el nuevo apellido paterno: ");
      scanf("%49s", firstLastName);

      data.firstLastName = firstLastName;

      break;
    case 3:
      char secondLastName[50];

      printf("\nIngresa el nuevo apellido materno: ");
      scanf("%49s", secondLastName);

      data.secondLastName = secondLastName;

      break;
    case 4:
      char major[50];

      printf("\nIngresa la nueva carrera de ingenieria: ");
      scanf("%49s", major);

      static char majorFixed[20];
      strncpy(majorFixed, major, sizeof(majorFixed)-1);

      majorFixed[sizeof(majorFixed)-1] = '\0';
      data.major = majorFixed;

      break;
    case 5:
      return;
    default:
      printf("\nOpcion no valida, no se realizaron cambios.\n");

      return;
  }

  database.students.updateByCode(code, &data);

  printf("\nEstudiante actualizado!\n");
  printf("--------------------------------\n");
}
