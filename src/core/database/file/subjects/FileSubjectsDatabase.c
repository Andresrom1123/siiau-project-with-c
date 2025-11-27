#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../../Subject.h"
#include "../../../../lib/generateCode/generateCode.h"
#include "../../../../database/subjectsRepository/CreateSubjectData.h"
#include "../../../../database/subjectsRepository/SubjectsRepository.h"
#include "../../../../database/subjectsRepository/SubjectList.h"

#define SUBJECTS_FILE_PATH "src/core/database/file/subjects/storage.txt"

Subject createSubject(const CreateSubjectData *data) {
  Subject subject;

  FILE *file = fopen(SUBJECTS_FILE_PATH, "a");

  if (!file) {
    printf("Error: %s not found.\n", SUBJECTS_FILE_PATH);

    return subject;
  } else {
    strcpy(subject.name, data->name);

    char code[10];

    subject.code = generateCode(code);

    fprintf(
      file,
      "%d:%s\n",
      subject.code,
      subject.name
    );

    fclose(file);

    return subject;
  }
}

SubjectList findAllSubjects() {
  SubjectList list;

  list.items = NULL;
  list.count = 0;

  FILE *file = fopen(SUBJECTS_FILE_PATH, "r");

  if (!file) {
    printf("Error: %s not found.\n", SUBJECTS_FILE_PATH);

    return list;
  }

  char line[512];
  int capacity = 10;

  list.items = malloc(sizeof(Subject) * capacity);

  while (fgets(line, sizeof(line), file)) {
    if (list.count >= capacity) {
      capacity *= 2;
      list.items = realloc(list.items, sizeof(Subject) * capacity);
    }

    line[strcspn(line, "\n")] = 0;

    Subject subject;

    char *token = strtok(line, ":");
    subject.code = atoi(token);

    token = strtok(NULL, ":");
    strcpy(subject.name, token);

    list.items[list.count++] = subject;
  }

  fclose(file);

  return list;
}

SubjectsRepository newFileSubjectsDatabase() {
  SubjectsRepository repo;

  repo.create = &createSubject;
  repo.findAll = &findAllSubjects;

  return repo;
}
