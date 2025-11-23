#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "../../../Student.h"

#include "../../../../database/studentsRepository/CreateStudentData.h"
#include "../../../../database/studentsRepository/StudentsRepository.h"
#include "../../../../database/studentsRepository/StudentList.h"

#define STUDENTS_FILE_PATH "src/core/database/file/students/storage.txt"

Student create(const CreateStudentData *data) {
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

    student.code = 123;

    fprintf(
      file,
      "%d:%s:%s:%s:%s\n",
      student.code,
      student.name,
      student.firstLastName,
      student.secondLastName,
      student.major
    );

    fclose(file);

    return student;
  }
}

StudentList findAll() {
  StudentList list;

  list.items = NULL;
  list.count = 0;

  FILE *file = fopen(STUDENTS_FILE_PATH, "r");

  if (!file) {
    printf("Error: %s not found.\n", STUDENTS_FILE_PATH);

    return list;
  }

  char line[512];
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

    student.subjects = malloc(strlen(token) + 1);
    strcpy(student.subjects, token);

    list.items[list.count++] = student;
  }

  fclose(file);

  return list;
}

StudentsRepository newFileStudentsDatabase() {
  StudentsRepository repo;

  repo.create = &create;
  repo.findAll = &findAll;

  return repo;
}
