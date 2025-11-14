CC = gcc
CFLAGS = -Wall -Wextra -std=c11

SRC = src/main.c \
	src/core/database/memory/MemoryDatabase.c \
	src/core/database/memory/MemoryStudentsDatabase.c

OUT = dist/app

all: dist $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(OUT)

run: all
	./$(OUT)

clean:
	rm -f $(OUT)

dist:
	mkdir -p dist
