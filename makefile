CC = gcc
CFLAGS = -Wall -Werror -Ofast -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=objs/%.o)
TARGET = main.exe

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

objs/%.o: src/%.c
	-@mkdir objs > NUL 2>&1
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	-@rmdir /S /Q objs > NUL 2>&1
	-@del /Q $(TARGET) > NUL 2>&1
