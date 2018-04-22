CFLAGS = -Wall -Werror -std=c99
OBJ = gcc -c $< -o $@ $(CFLAGS)
MKDIR_BUILD = mkdir -p build

.PHONY: all clean

all: bin/chess.exe

bin/chess.exe: build/main.o build/board_print_plain.o build/board_start.o build/board.o build/board_read.o
	mkdir -p bin
	gcc $^ -o $@ $(CFLAGS)

build/main.o: src/main.c
	$(MKDIR_BUILD)
	$(OBJ)

build/board_print_plain.o: src/board_print_plain.c src/board_print_plain.h
	$(MKDIR_BUILD)
	$(OBJ)

build/board_start.o: src/board_start.c src/board_start.h
	$(MKDIR_BUILD)
	$(OBJ)

build/board.o: src/board.c src/board.h
	$(MKDIR_BUILD)
	$(OBJ)

build/board_read.o: src/board_read.c src/board_read.h
	$(MKDIR_BUILD)
	$(OBJ)

clean:
	rm -r -f build
	rm -r -f bin
