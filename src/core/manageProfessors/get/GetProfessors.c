#include <stdio.h>

#include "../../../database/Database.h"
#include "../../../database/professorsRepository/ProfessorList.h"

void GetProfessors(Database database) {
  printf("\n---- LISTA DE PROFESORES ----\n\n");

  ProfessorList professorList = database.professors.findAll();

  if (professorList.count == 0) {
    printf("No hay profesores registrados. \n");

    return;
  }
 
  for (int i = 0; i < professorList.count; i++) {
    Professor *professors = professorList.items;

    printf("Codigo: %d\n", professors[i].code);
    printf("Nombre: %s %s %s\n",
      professors[i].name,
      professors[i].firstLastName,
      professors[i].secondLastName
    );
    printf("Departamento: %s\n", professors[i].department);
    printf("--------------------\n");
  }
}
