#include "../../../database/Database.h"

#include "./professors/FileProfessorsDatabase.h"
#include "./students/FileStudentsDatabase.h"
#include "./subjects/FileSubjectsDatabase.h"

Database newFileDatabase() {
  Database database;

  database.professors = newFileProfessorsDatabase();
  database.subjects = newFileSubjectsDatabase();
  database.students = newFileStudentsDatabase(database);

  return database;
}
