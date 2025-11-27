#include <stdio.h>

#include "../../../database/Database.h"

void AssignSubject(Database database) {
  int studentCode;
  int subjectCode;

  printf("Ingresa el codigo del estudiante: ");
  scanf("%d", &studentCode);

  printf("Ingresa el codigo de la materia: ");
  scanf("%d", &subjectCode);

  Student *student = database.students.findByCode(studentCode);

  if (student == NULL) {
    printf("\n El estudiante no existe");

    return;
  }

  for (int j = 0; j < student->subjects->count; j++) {
    Subject subject = student->subjects->items[j];

    if (subject.code == subjectCode) {
      printf("\n El alumno ya tiene registrada esa materia \n");

      return;
    }
  }

  Subject *subject = database.subjects.findByCode(subjectCode);

  if (subject == NULL) {
    printf("\n La materia no existe");

    return;
  }

  database.students.assignSubject(studentCode, subjectCode);

  printf("\n Se le ha asignado la materia! \n");
}
