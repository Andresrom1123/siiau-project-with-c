#ifndef PROFESSORS_REPOSITORY_H
#define PROFESSORS_REPOSITORY_H

#include "../../core/Professor.h"

#include "./CreateProfessorData.h"
#include "./UpdateProfessorData.h"
#include "./ProfessorList.h"

typedef struct {
  Professor (*create)(const CreateProfessorData *data);
  void (*deleteByCode)(const int code);
  ProfessorList (*findAll)();
  Professor* (*findByCode)(const int code);
  void (*updateByCode)(const int code, const UpdateProfessorData *data);
} ProfessorsRepository;

#endif
