#ifndef PROFESSORS_REPOSITORY_H
#define PROFESSORS_REPOSITORY_H

#include "../../core/Professor.h"

#include "./CreateProfessorData.h"
#include "./ProfessorList.h"

typedef struct {
  Professor (*create)(const CreateProfessorData *data);
  ProfessorList (*findAll)();
} ProfessorsRepository;

#endif
