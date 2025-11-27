#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../../../Professor.h"
#include "../../../../lib/generateCode/generateCode.h"
#include "../../../../database/professorsRepository/CreateProfessorData.h"
#include "../../../../database/professorsRepository/ProfessorsRepository.h"
#include "../../../../database/professorsRepository/ProfessorList.h"

#define MAX_LINE 512
#define PROFESSORS_FILE_PATH "src/core/database/file/professors/storage.txt"

Professor createProfessor(const CreateProfessorData *data) {
  srand(time(NULL));

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

Professor* findProfessorByCode(const int code) {
  FILE *file = fopen(PROFESSORS_FILE_PATH, "r");

  if (!file) {
    printf("Error: file not found.\n");

    return NULL;
  }

  char line[MAX_LINE];

  while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = 0;

    char *token = strtok(line, ":");
    int fileCode = atoi(token);

    if (fileCode != code) continue;

    Professor *professor = malloc(sizeof(Professor));

    if (!professor) {
      fclose(file);

      return NULL;
    }

    professor->code = fileCode;

    token = strtok(NULL, ":");
    strcpy(professor->name, token);

    token = strtok(NULL, ":");
    strcpy(professor->firstLastName, token);

    token = strtok(NULL, ":");
    strcpy(professor->secondLastName, token);

    token = strtok(NULL, ":");
    strcpy(professor->department, token);

    fclose(file);

    return professor;
  }

  fclose(file);

  return NULL;
}

void updateProfessorByCode(const int code, const UpdateProfessorData *data) {
  FILE *file = fopen(PROFESSORS_FILE_PATH, "r");

  if (!file) {
    printf("Error: professors file not found.\n");

    return;
  }

  char line[MAX_LINE];
  char newContent[4096] = "";

  while (fgets(line, sizeof(line), file)) {
    char copy[MAX_LINE];

    strcpy(copy, line);

    copy[strcspn(copy, "\n")] = 0;

    char *token = strtok(copy, ":");

    if (!token) continue;

    int studentCode = atoi(token);

    if (studentCode == code) {
      strtok(NULL, ":");
      strtok(NULL, ":");
      strtok(NULL, ":");
      strtok(NULL, ":");

      char *subjects = strtok(NULL, ":");

      if (!subjects) subjects = "";

      char buffer[MAX_LINE * 2];

      snprintf(buffer, sizeof(buffer), "%d:%s:%s:%s:%s:%s\n",
        studentCode,
        data->name,
        data->firstLastName,
        data->secondLastName,
        data->department,
        subjects
      );

      strcat(newContent, buffer);
    } else {
      strcat(newContent, line);
    }
  }

  fclose(file);

  file = fopen(PROFESSORS_FILE_PATH, "w");

  if (!file) {
    printf("Error opening file for writing.\n");

    return;
  }

  fprintf(file, "%s", newContent);

  fclose(file);
}

ProfessorsRepository newFileProfessorsDatabase() {
  ProfessorsRepository repo;

  repo.create = &createProfessor;
  repo.findAll = &findAllProfessors;
  repo.findByCode = &findProfessorByCode;
  repo.updateByCode = &updateProfessorByCode;

  return repo;
}
