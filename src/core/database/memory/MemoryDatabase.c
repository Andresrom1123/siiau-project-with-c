#include "../../../database/Database.h"

#include "./MemoryStudentsDatabase.h"

Database newMemoryDatabase() {
  Database database;

  database.students = newMemoryStudentsDatabase();

  return database;
}
