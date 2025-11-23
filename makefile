CC = gcc
CFLAGS = -Wall -Wextra -std=c11

# TODO: When GetProfessors and CreateProfessors are created, implement them
SRC = src/main.c \
	src/core/manageProfessors/manageProfessors.c \
	src/core/manageProfessors/create/CreateProfessor.c \
	src/core/manageStudents/manageStudents.c \
	src/core/manageStudents/create/CreateStudent.c \
	src/core/manageStudents/get/GetStudents.c \
	src/core/database/file/FileDatabase.c \
	src/core/database/file/students/FileStudentsDatabase.c \
	src/core/database/file/professors/FileProfessorsDatabase.c

OUT = dist/app

all: dist $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

dist:
	mkdir -p dist
