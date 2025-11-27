CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = src/main.c \
	src/lib/generateCode/generateCode.c \
	src/core/manageProfessors/manageProfessors.c \
	src/core/manageProfessors/create/CreateProfessor.c \
	src/core/manageProfessors/get/GetProfessors.c \
	src/core/manageProfessors/get/GetProfessor.c \
	src/core/manageProfessors/modify/ModifyProfessor.c \
	src/core/manageStudents/assignSubject/AssignSubject.c \
	src/core/manageStudents/create/CreateStudent.c \
	src/core/manageStudents/delete/DeleteStudent.c \
	src/core/manageStudents/get/GetStudent.c \
	src/core/manageStudents/get/GetStudents.c \
	src/core/manageStudents/modify/ModifyStudent.c \
	src/core/manageSubjects/create/CreateSubject.c \
	src/core/manageStudents/manageStudents.c \
	src/core/manageSubjects/manageSubjects.c \
	src/core/database/file/FileDatabase.c \
 	src/core/database/file/professors/FileProfessorsDatabase.c \
	src/core/database/file/students/FileStudentsDatabase.c \
	src/core/database/file/subjects/FileSubjectsDatabase.c
	
OUT = dist/app

all: dist $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

dist:
	mkdir -p dist
