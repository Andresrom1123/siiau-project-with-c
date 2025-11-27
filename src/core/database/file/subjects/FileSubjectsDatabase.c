#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

#include "../../../Subject.h"
#include "../../../SubjectList.h"
#include "../../../../lib/generateCode/generateCode.h"
#include "../../../../database/subjectsRepository/CreateSubjectData.h"
#include "../../../../database/subjectsRepository/UpdateSubjectData.h"
#include "../../../../database/subjectsRepository/SubjectsRepository.h"

#define MAX_LINE 512
#define SUBJECTS_FILE_PATH "src/core/database/file/subjects/storage.txt"

Subject createSubject(const CreateSubjectData *data) {
  srand(time(NULL));

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

void deleteSubjectByCode(const int code) {
  FILE *file = fopen(SUBJECTS_FILE_PATH, "r");

  if (!file) {
    printf("Error: subjects file not found.\n");
    return;
  }

  char line[MAX_LINE];
  char newContent[4096] = "";

  while (fgets(line, sizeof(line), file)) {
    char copy[MAX_LINE];

    strcpy(copy, line);

    copy[strcspn(copy, "\n")] = 0;

    char *token = strtok(copy, ":");

    if (!token) {
      strcat(newContent, line);

      continue;
    }

    int subjectCode = atoi(token);

    if (subjectCode == code) {
      continue;
    }

    strcat(newContent, line);
  }

  fclose(file);

  file = fopen(SUBJECTS_FILE_PATH, "w");

  if (!file) {
    printf("Error opening file for writing.\n");

    return;
  }

  fprintf(file, "%s", newContent);
  fclose(file);
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

Subject* findByCodeSubject(const int code) {
  FILE *file = fopen(SUBJECTS_FILE_PATH, "r");

  if (!file) {
    printf("Error: file not found.\n");
    return NULL;
  }

  char line[512];

  while (fgets(line, sizeof(line), file)) {
    line[strcspn(line, "\n")] = 0;

    Subject subject;

    char *token = strtok(line, ":");

    if (!token) continue;

    subject.code = atoi(token);

    token = strtok(NULL, ":");
    if (!token) continue;

    strcpy(subject.name, token);

    if (subject.code == code) {
      Subject *result = malloc(sizeof(Subject));

      if (!result) {
        printf("Error allocating memory.\n");

        fclose(file);

        return NULL;
      }

      result->code = subject.code;

      strcpy(result->name, subject.name);

      fclose(file);

      return result;
    }
  }

  fclose(file);

  return NULL;
}

void updateStudentByCode(const int code, const UpdateSubjectData *data) {
  FILE *file = fopen(SUBJECTS_FILE_PATH, "r");

  if (!file) {
    printf("Error: subjects file not found.\n");

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
      char buffer[MAX_LINE * 2];

      snprintf(buffer, sizeof(buffer), "%d:%s\n",
        studentCode,
        data->name
      );

      strcat(newContent, buffer);
    } else {
      strcat(newContent, line);
    }
  }

  fclose(file);

  file = fopen(SUBJECTS_FILE_PATH, "w");

  if (!file) {
    printf("Error opening file for writing.\n");

    return;
  }

  fprintf(file, "%s", newContent);

  fclose(file);
}

SubjectsRepository newFileSubjectsDatabase() {
  SubjectsRepository repo;

  repo.create = &createSubject;
  repo.deleteByCode = &deleteSubjectByCode;
  repo.findAll = &findAllSubjects;
  repo.findByCode = &findByCodeSubject;
  repo.updateByCode = &updateStudentByCode;

  return repo;
}
