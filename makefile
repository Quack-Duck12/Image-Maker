CC = gcc
LDFLAGS = -static -Ofast
CFLAGS = -Wall -Werror -Ofast -Iinclude

SRC = $(wildcard src/*.c)
OBJ = $(SRC:src/%.c=objs/%.o)
TARGET = main.exe

$(TARGET): $(OBJ)
	$(CC) $(OBJ) $(LDFLAGS) -o $(TARGET)

objs/%.o: src/%.c | objs
	$(CC) $(CFLAGS) -c $< -o $@

objs:
	mkdir objs

.PHONY: clean
clean:
	-@rmdir /S /Q objs > NUL 2>&1
	-@del /Q $(TARGET) > NUL 2>&1
