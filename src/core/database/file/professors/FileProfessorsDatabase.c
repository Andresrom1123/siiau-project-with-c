#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../../Professor.h"

#include "../../../../database/professorsRepository/CreateProfessorData.h"
#include "../../../../database/professorsRepository/ProfessorsRepository.h"
#include "../../../../database/professorsRepository/ProfessorList.h"

#define STUDENTS_FILE_PATH "src/core/database/file/professors/storage.txt"

// TODO: Implement this function (LEO)
Professor create(const CreateProfessorData *data) {
  Professor professor;

  return professor;
}

// TODO: Implement this function (RAFA)
ProfessorList findAll() {
  ProfessorList list;

  return list;
}

ProfessorsRepository newFileProfessorsDatabase() {
  ProfessorsRepository repo;

  repo.create = &create;
  repo.findAll = &findAll;

  return repo;
}

