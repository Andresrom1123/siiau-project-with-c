#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../../Professor.h"

#include "../../../../database/professorsRepository/CreateProfessorData.h"
#include "../../../../database/professorsRepository/ProfessorsRepository.h"
#include "../../../../database/professorsRepository/ProfessorList.h"

#define PROFESORS_FILE_PATH "src/core/database/file/professors/storage.txt"

Professor createProfessor(const CreateProfessorData *data) {
  Professor professor;

   FILE *file = fopen(PROFESORS_FILE_PATH, "a");

  if (!file) {
    printf("Error: %s not found.\n", PROFESORS_FILE_PATH);
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
ProfessorList findAllProfessors(){ ProfessorList list;

  list.items = NULL;
  list.count = 0;

  FILE *file = fopen(PROFESORS_FILE_PATH, "r");

  if (!file) {
    printf("Error: %s not found.\n", PROFESORS_FILE_PATH);

    return list;
  }

  char line[512];
  int capacity = 10;

  list.items = malloc(sizeof(Professor) * capacity);

  while (fgets(line, sizeof(line), file)) {
    if (list.count >= capacity) {
      capacity *= 2;
      list.items = realloc(list.items, sizeof(Professor) * capacity);
    }

    line[strcspn(line, "\n")] = 0;

    Professor professor;

    char *token = strtok(line, ":");
    professor.code = atoi(token);

    token = strtok(NULL, ":");
    strcpy(professor.name, token);

    token = strtok(NULL, ":");
    strcpy(professor.firstLastName, token);

    token = strtok(NULL, ":");
    strcpy(professor.secondLastName, token);

    token = strtok(NULL, ":");
    strcpy(professor.department, token);

    token = strtok(NULL, ":");

    professor.subject = malloc(strlen(token) + 1);
    strcpy(professor.subject, token);

    list.items[list.count++] = professor;
  }

  fclose(file);

  return list;
  }
ProfessorsRepository newFileProfessorsDatabase() {
  ProfessorsRepository repo;

  repo.create = &createProfessor;
  repo.findAll = &findAllProfessors;

  return repo;
}

