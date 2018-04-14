.PHONY: all clean

all: build/main.o build/board_print_plain.o build/board_start.o
	gcc -std=c99 build/main.o build/board_print_plain.o build/board_start.o -o bin/chess.exe -Wall -Werror 

build/main.o: src/main.c
	gcc -std=c99 -c src/main.c -o build/main.o -Wall -Werror

build/board_print_plain.o: src/board_print_plain.c
	gcc -std=c99 -c src/board_print_plain.c -o build/board_print_plain.o -Wall -Werror

build/board_start.o: src/board_start.c
	gcc -std=c99 -c src/board_start.c -o build/board_start.o -Wall -Werror

clean:
	rm build/*.o
	rm bin/*.exe
