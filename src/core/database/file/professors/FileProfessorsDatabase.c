#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../../Professor.h"
#include "../../../../lib/generateCode/generateCode.h"
#include "../../../../database/professorsRepository/CreateProfessorData.h"
#include "../../../../database/professorsRepository/ProfessorsRepository.h"
#include "../../../../database/professorsRepository/ProfessorList.h"

#define PROFESSORS_FILE_PATH "src/core/database/file/professors/storage.txt"

Professor createProfessor(const CreateProfessorData *data) {
  Professor professor;

   FILE *file = fopen(PROFESSORS_FILE_PATH, "a");

  if (!file) {
    printf("Error: %s not found.\n", PROFESSORS_FILE_PATH);
  } else {
    strcpy(professor.name, data->name);
    strcpy(professor.firstLastName, data->firstLastName);
    strcpy(professor.secondLastName, data->secondLastName);
    strcpy(professor.department, data->department);

    char code[10];

    professor.code = generateCode(code);

    fprintf(
      file,
      "%d:%s:%s:%s:%s:%s\n",
      professor.code,
      professor.name,
      professor.firstLastName,
      professor.secondLastName,
      professor.department,
      ""
    );
  }

  fclose(file);

  return professor;
}

ProfessorList findAllProfessors() {
  ProfessorList list;

  list.items = NULL;
  list.count = 0;

  FILE *file = fopen(PROFESSORS_FILE_PATH, "r");

  if (!file) {
    printf("Error: %s not found.\n", PROFESSORS_FILE_PATH);

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
