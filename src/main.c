#include <stdio.h>

#include "./core/database/memory/MemoryDatabase.h"

int main() {
  Database database = newMemoryDatabase();

  CreateStudentData data = {
    "Andres",
    "Romero",
    "Vergara",
    12345,
    "Informatica"
  };

  Student student = database.students.create(&data);

  printf("Estudiante: %s %s %s %s — Código: %d\n",
    student.id,
    student.name,
    student.firstLastName,
    student.secondLastName,
    student.code
  );

  return 0;
}
