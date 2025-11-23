#include "../../../database/Database.h"

#include "./professors/FileProfessorsDatabase.h"
#include "./students/FileStudentsDatabase.h"

Database newFileDatabase() {
  Database database;

  database.students = newFileStudentsDatabase();
  database.professors = newFileProfessorsDatabase();

  return database;
}
