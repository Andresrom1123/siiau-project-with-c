#ifndef SUBJECTS_REPOSITORY_H
#define SUBJECTS_REPOSITORY_H

#include "../../core/Subject.h"

#include "./CreateSubjectData.h"
#include "./UpdateSubjectData.h"

typedef struct {
  Subject (*create)(const CreateSubjectData *data);
  void (*deleteByCode)(const int code);
  SubjectList (*findAll)();
  Subject* (*findByCode)(const int code);
  void (*updateByCode)(const int code, const UpdateSubjectData *data);
} SubjectsRepository;

#endif
