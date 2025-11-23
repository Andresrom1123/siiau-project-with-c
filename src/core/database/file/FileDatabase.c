#include "../../../database/Database.h"

#include "./students/FileStudentsDatabase.h"

Database newFileDatabase() {
  Database database;

  database.students = newFileStudentsDatabase();

  return database;
}
