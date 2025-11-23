#include <stdio.h>
#include <string.h>

#include "../../../database/Database.h"
#include "../../../database/studentsRepository/CreateStudentData.h"

void CreateStudent(Database database) {
  char name[50];
  char firstLastName[50];
  char secondLastName[50];
  char major[50];

  printf("\nIngresa el nombre del estudiante: ");
  scanf("%49s", name);

  printf("\nIngresa el apellido paterno del estudiante: ");
  scanf("%49s", firstLastName);

  printf("\nIngresa el apellido materno del estudiante: ");
  scanf("%49s", secondLastName);

  printf("\nIngresa la carrera de Ingieneria del estudiante: ");
  scanf("%49s", major);
  
  CreateStudentData data = {
    name,
    firstLastName,
    secondLastName,
    major
  };
  
  database.students.create(&data);

  printf("\nSe ha create el nuevo estudiante correctamente!");
}
