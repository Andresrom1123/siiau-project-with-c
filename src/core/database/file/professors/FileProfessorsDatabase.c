#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../../Professor.h"

#include "../../../../database/professorsRepository/CreateProfessorData.h"
#include "../../../../database/professorsRepository/ProfessorsRepository.h"
#include "../../../../database/professorsRepository/ProfessorList.h"

#define PROFESORS_FILE_PATH "src/core/database/file/professors/storage.txt"

// TODO: Implement this function (LEO)
Professor createProfessor(const CreateProfessorData *data) {
  Professor professor;

   FILE *file = fopen(PROFESORS_FILE_PATH, "a");

  if (!file) {
    printf("Error: %s not found.\n", PROFESORS_FILE_PATH);

    return professor;
  } else {
    strcpy(professor.name, data->name);
    strcpy(professor.firstLastName, data->firstLastName);
    strcpy(professor.secondLastName, data->secondLastName);
    strcpy(professor.department, data->department);

    professor.code = 123;

    fprintf(
      file,
      "%d:%s:%s:%s:%s\n",
      professor.code,
      professor.name,
      professor.firstLastName,
      professor.secondLastName,
      professor.department
    );
  }

  fclose(file);

  return professor;
}

// TODO: Implement this function (RAFA)
/* ProfessorList findAll() {
  ProfessorList list;

  return list;
} */

ProfessorsRepository newFileProfessorsDatabase() {
  ProfessorsRepository repo;

  repo.create = &createProfessor;
  // repo.findAll = &findAll;

  return repo;
}

