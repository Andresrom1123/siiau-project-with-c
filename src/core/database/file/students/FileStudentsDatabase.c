#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../../Student.h"
#include "../../../../lib/generateCode/generateCode.h"
#include "../../../../database/Database.h"
#include "../../../../database/studentsRepository/CreateStudentData.h"
#include "../../../../database/studentsRepository/StudentsRepository.h"
#include "../../../../database/studentsRepository/StudentList.h"

char *strtok_r(char *, const char *, char **);

#define MAX_LINE 512
#define MAX_STUDENTS 200
#define STUDENTS_FILE_PATH "src/core/database/file/students/storage.txt"

Student createStudent(const CreateStudentData *data) {
  Student student;

  FILE *file = fopen(STUDENTS_FILE_PATH, "a");

  if (!file) {
    printf("Error: %s not found.\n", STUDENTS_FILE_PATH);

    return student;
  } else {
    strcpy(student.name, data->name);
    strcpy(student.firstLastName, data->firstLastName);
    strcpy(student.secondLastName, data->secondLastName);
    strcpy(student.major, data->major);

    char code[10];

    student.code = generateCode(code);

    fprintf(
      file,
      "%d:%s:%s:%s:%s:%s\n",
      student.code,
      student.name,
      student.firstLastName,
      student.secondLastName,
      student.major,
      ""
    );

    fclose(file);

    return student;
  }
}

StudentList findAllStudents(const void *database) {
  Database *db = (Database*) database;

  StudentList list;

  list.items = NULL;
  list.count = 0;

  FILE *file = fopen(STUDENTS_FILE_PATH, "r");

  if (!file) {
    printf("Error: %s not found.\n", STUDENTS_FILE_PATH);

    return list;
  }

  char line[MAX_LINE];
  int capacity = 10;

  list.items = malloc(sizeof(Student) * capacity);

  while (fgets(line, sizeof(line), file)) {
    if (list.count >= capacity) {
      capacity *= 2;
      list.items = realloc(list.items, sizeof(Student) * capacity);
    }

    line[strcspn(line, "\n")] = 0;

    Student student;

    char *token = strtok(line, ":");
    student.code = atoi(token);

    token = strtok(NULL, ":");
    strcpy(student.name, token);

    token = strtok(NULL, ":");
    strcpy(student.firstLastName, token);

    token = strtok(NULL, ":");
    strcpy(student.secondLastName, token);

    token = strtok(NULL, ":");
    strcpy(student.major, token);

    token = strtok(NULL, ":");
    
    SubjectList *subjectList = malloc(sizeof(SubjectList));
    subjectList->items = NULL;
    subjectList->count = 0;

    if (!token || strlen(token) == 0 || strcmp(token, ".") == 0) {
      student.subjects = subjectList;

      list.items[list.count++] = student;

      continue;
    }

    char *buffer = malloc(strlen(token) + 1);

    strcpy(buffer, token);

    int capacity = 5;
    subjectList->items = malloc(sizeof(Subject) * capacity);

    char *saveptr = NULL;
    char *subjToken = strtok_r(buffer, ".", &saveptr);

    while (subjToken) {
      if (subjectList->count >= capacity) {
        capacity *= 2;
        subjectList->items = realloc(subjectList->items, sizeof(Subject) * capacity);
      }

      int subjectCode = atoi(subjToken);

      Subject *fullSubject = db->subjects.findByCode(subjectCode);

      if (fullSubject) {
        subjectList->items[subjectList->count++] = *fullSubject;
      } else {
        subjectList->items[subjectList->count].code = subjectCode;

        strcpy(subjectList->items[subjectList->count].name, "Unknown");

        subjectList->count++;
      }

      subjToken = strtok_r(NULL, ".", &saveptr);
    }

    if (subjectList->count > 0) {
      subjectList->items = realloc(subjectList->items, sizeof(Subject) * subjectList->count);
    }

    free(buffer);

    subjectList->items = realloc(subjectList->items, sizeof(Subject) * subjectList->count);
    student.subjects = subjectList;


    list.items[list.count++] = student;
  }

  fclose(file);

  return list;
}

Student* findByCodeStudent(const int code, const void *database) {
  Database *db = (Database*) database;

  FILE *file = fopen(STUDENTS_FILE_PATH, "r");

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

    Student *student = malloc(sizeof(Student));

    if (!student) {
      fclose(file);

      return NULL;
    }

    student->code = fileCode;

    token = strtok(NULL, ":");
    strcpy(student->name, token);

    token = strtok(NULL, ":");
    strcpy(student->firstLastName, token);

    token = strtok(NULL, ":");
    strcpy(student->secondLastName, token);

    token = strtok(NULL, ":");
    strcpy(student->major, token);

    token = strtok(NULL, ":");

    SubjectList *subjectList = malloc(sizeof(SubjectList));
    subjectList->items = NULL;
    subjectList->count = 0;

    if (!token || strlen(token) == 0 || strcmp(token, ".") == 0) {
      student->subjects = subjectList;

      fclose(file);

      return student;
    }

    char *buffer = malloc(strlen(token)+1);

    strcpy(buffer, token);

    int capacity = 5;

    subjectList->items = malloc(sizeof(Subject) * capacity);

    char *subjToken = strtok(buffer, ".");

    while (subjToken) {
      if (subjectList->count >= capacity) {
        capacity *= 2;
        subjectList->items = realloc(subjectList->items, sizeof(Subject) * capacity);
      }

      int subjectCode = atoi(subjToken);

      Subject *fullSubject = db->subjects.findByCode(subjectCode);

      if (fullSubject) {
        subjectList->items[subjectList->count++] = *fullSubject;
      } else {
        subjectList->items[subjectList->count].code = subjectCode;

        strcpy(subjectList->items[subjectList->count].name, "Unknown");

        subjectList->count++;
      }

      subjToken = strtok(NULL, ".");
    }

    free(buffer);

    subjectList->items = realloc(subjectList->items, sizeof(Subject) * subjectList->count);
    student->subjects = subjectList;

    fclose(file);

    return student;
  }

  fclose(file);

  return NULL;
}

void assignSubjectToStudent(const int studentCode, const int subjectCode) {
  FILE *file = fopen(STUDENTS_FILE_PATH, "r");

  if (!file) {
   printf("Error: %s not found.\n", STUDENTS_FILE_PATH);

   return;
  }

  char line[MAX_LINE];
  char newFileContent[MAX_STUDENTS * MAX_LINE] = ""; 

  while (fgets(line, sizeof(line), file)) {
    char originalLine[MAX_LINE];
    strcpy(originalLine, line);

    originalLine[strcspn(originalLine, "\n")] = 0;

    char *token = strtok(originalLine, ":");
    int fileStudentCode = atoi(token);

    if (fileStudentCode == studentCode) {
      char *name = strtok(NULL, ":");
      char *firstLast = strtok(NULL, ":");
      char *secondLast = strtok(NULL, ":");
      char *major = strtok(NULL, ":");
      char *subjects = strtok(NULL, ":");

      char updatedSubjects[MAX_LINE];

      if (subjects && strlen(subjects) > 0) {
        snprintf(updatedSubjects, sizeof(updatedSubjects), "%s.%d", subjects, subjectCode);
      } else {
        snprintf(updatedSubjects, sizeof(updatedSubjects), "%d", subjectCode);
      }

      char buffer[MAX_LINE * 4];

      snprintf(buffer, sizeof(buffer), "%d:%s:%s:%s:%s:%s\n",
        fileStudentCode, name, firstLast, secondLast, major, updatedSubjects
      );

      strncpy(line, buffer, sizeof(line)-1);

      line[sizeof(line)-1] = '\0';
    }

    strcat(newFileContent, line);
  }

  fclose(file);

  file = fopen(STUDENTS_FILE_PATH, "w");

  if (!file) {
    printf("Error: %s not found.\n", STUDENTS_FILE_PATH);

    return;
  }

  fprintf(file, "%s", newFileContent);

  fclose(file);
}


StudentsRepository newFileStudentsDatabase() {
  StudentsRepository repo;

  repo.create = &createStudent;
  repo.findAll = &findAllStudents;
  repo.findByCode = &findByCodeStudent;
  repo.assignSubject = &assignSubjectToStudent;

  return repo;
}
