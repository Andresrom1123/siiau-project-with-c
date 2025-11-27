#include <stdio.h>

#include "../../../database/Database.h"
#include "../../SubjectList.h"

void GetSubjects(Database database) {
  SubjectList subjectList = database.subjects.findAll();

  for (int i = 0; i < subjectList.count; i++) {
    Subject *subjects = subjectList.items;

    printf("Code: %d - Nombre: %s\n",
      subjects[i].code,
      subjects[i].name
    );

    printf("\n--------------------------------\n");
  }
}
