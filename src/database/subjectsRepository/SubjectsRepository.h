#ifndef SUBJECTS_REPOSITORY_H
#define SUBJECTS_REPOSITORY_H

#include "../../core/Subject.h"

#include "./CreateSubjectData.h"

typedef struct {
  Subject (*create)(const CreateSubjectData *data);
  SubjectList (*findAll)();
  Subject* (*findByCode)(const int code);
} SubjectsRepository;

#endif
