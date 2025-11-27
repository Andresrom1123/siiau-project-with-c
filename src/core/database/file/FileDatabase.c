#include "../../../database/Database.h"

#include "./professors/FileProfessorsDatabase.h"
#include "./students/FileStudentsDatabase.h"
#include "./subjects/FileSubjectsDatabase.h"

Database newFileDatabase() {
  Database database;

  database.professors = newFileProfessorsDatabase();
  database.students = newFileStudentsDatabase();
  database.subjects = newFileSubjectsDatabase();

  return database;
}
