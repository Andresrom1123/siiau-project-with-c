#ifndef SUBJECTS_REPOSITORY_H
#define SUBJECTS_REPOSITORY_H

#include "../../core/Subject.h"

#include "./CreateSubjectData.h"
#include "./Subject.h"

typedef struct {
  Subject (*create)(const CreateSubjectData *data);
  Subject (*findAll)();
} StudentsRepository;

#endif
