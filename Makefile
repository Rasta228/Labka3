all: main.o board_print_plain.o board_start.o
	gcc build/main.o build/board_print_plain.o build/board_start.o -o bin/chess.exe -Wall -Werror

main.o: src/main.c
	gcc -c src/main.c -o build/main.o

board_print_plain.o: src/board_print_plain.c
	gcc -c src/board_print_plain.c -o build/board_print_plain.o

board_start.o: src/board_start.c
	gcc -c src/board_start.c -o build/board_start.o


