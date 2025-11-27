#include <stdio.h>
#include <string.h>

#include "../../../database/Database.h"
#include "../../../database/subjectsRepository/CreateSubjectData.h"

void CreateSubject(Database database) {
  char name[50];

  printf("\nIngresa el nombre de la materia: ");
  scanf("%49s", name);
  
  CreateSubjectData data = { name };
  
  database.subjects.create(&data);

  printf("\nSe ha creado la nueva materia correctamente!\n");
}
