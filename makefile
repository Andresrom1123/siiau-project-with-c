CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = src/main.c \
	src/core/manageStudents/manageStudents.c \
	src/core/manageStudents/create/CreateStudent.c \
	src/core/database/file/FileDatabase.c \
	src/core/database/file/students/FileStudentsDatabase.c

OUT = dist/app

all: dist $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

dist:
	mkdir -p dist
