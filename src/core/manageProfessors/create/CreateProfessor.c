#include <stdio.h>
#include <string.h>

#include "../../../database/Database.h"
#include "../../../database/professorsRepository/CreateProfessorData.h"

// TODO: Implement this function (LEO)
void CreateProfessor(Database database) {
  char name[50];
  char firstLastName[50];
  char secondLastName[50];
  char department[50];   
  
  printf("\nIngresa el nombre del profesor: ");
  scanf("%49s", name);

  printf("\nIngresa el apellido paterno del profesor: ");
  scanf("%49s", firstLastName);

  printf("\nIngresa el apellido materno del profesor: ");
  scanf("%49s", secondLastName);

  printf("\nIngresa la materia de Ingieneria del profesor: ");
  scanf("%49s", department);

  CreateProfessorData data = {
    name,
    firstLastName,
    secondLastName,
    department
  };

  database.professors.create(&data);

  printf("\nSe ha creado el nuevo profesor correctamente!");

}
