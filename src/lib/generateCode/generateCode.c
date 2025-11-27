#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateCode(char *buffer) {
  int code = 100000000 + rand() % 900000000;

  sprintf(buffer, "%d", code);

  return code;
}
