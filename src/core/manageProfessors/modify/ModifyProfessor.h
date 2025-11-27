#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../../../database/Database.h"
#include "../../../core/Professor.h"
#include "../../../database/professorsRepository/UpdateProfessorData.h"

void ModifyProfessor(Database database) {
  int code;

  printf("\nIngresa el codigo del profesor que deseas modificar: ");
  scanf("%d", &code);

  Professor *professor = database.professors.findByCode(code);

  if (professor == NULL) {
    printf("\n El profesor no existe! \n");

    return;
  }

  int option;

  printf("\n¿Que deseas modificar?\n");
  printf("1. Nombre\n");
  printf("2. Apellido paterno\n");
  printf("3. Apellido materno\n");
  printf("4. Departamento\n");
  printf("5. Cancelar y salir\n");
  printf("Selecciona una opcion: ");
  scanf("%d", &option);

  UpdateProfessorData data;

  data.name = professor->name;
  data.firstLastName = professor->firstLastName;
  data.secondLastName = professor->secondLastName;
  data.department = professor->department;

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
      char department[50];

      printf("\nIngresa el nuevo departamento: ");
      scanf("%49s", department);

      static char departmentFixed[20];
      strncpy(departmentFixed, department, sizeof(departmentFixed)-1);

      departmentFixed[sizeof(departmentFixed)-1] = '\0';
      data.department = departmentFixed;

      break;
    case 5:
      return;
    default:
      printf("\nOpcion no valida, no se realizaron cambios.\n");

      return;
  }

  database.professors.updateByCode(code, &data);

  printf("\n Profesor actualizado!\n");
  printf("--------------------------------\n");
}
