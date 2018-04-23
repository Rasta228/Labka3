#include "board.h"
#include "board_read.h"
#include <string.h>
#include <stdlib.h>

void board(char deck[8][8]) {
    int flag = 1;
    do{
        char *input = board_read();
        int move[4];
        reformat_input(input, move);
        free(input);
        flag = check_move(deck, move);
    } while (flag);
}

int check_move(char deck[8][8], int move[]) {
    switch (deck[move[1]][move[0]]) {
        case 'p':
            return black_pwn(deck, move);
        case 'P':
            return white_pwn(deck, move);
        default:
            return 1;
        
    }
}
void reformat_input(char *input, int move[4]) {
    move[0] = input[0]-'a';
    move[1] = 8-(input[1]-'0');
    move[2] = input[3]-'a';
    move[3] = 8-(input[4]-'0');
}
int black_pwn(char deck[8][8], int move[]) {
    if ((move[2] == move[0] && deck[move[3]][move[2]] == ' ' &&
        (move[3] == move[1]+1 || (move[1] == 1 && move[3] == 3))) || (move[3] == move[1]+1 &&
        (move[2] == move[0]+1 || move[2] == move[0]-1) && deck[move[3]][move[2]]>='A' && deck[move[3]][move[2]]<='Z')) {
        deck[move[1]][move[0]] = ' ';
        deck[move[3]][move[2]] = 'p';
        return 0;
    }
    else return 1;
}

int white_pwn(char deck[8][8], int move[]) {
    if ((move[2] == move[0] && deck[move[3]][move[2]] == ' ' &&
        (move[3] == move[1]-1 || (move[1] == 6 && move[3] == 4))) || (move[3] == move[1]-1 &&
        (move[2] == move[0]+1 || move[2] == move[0]-1) && deck[move[3]][move[2]]>='a' && deck[move[3]][move[2]]<='z')) {
        deck[move[1]][move[0]] = ' ';
        deck[move[3]][move[2]] = 'P';
        return 0;
    }
    else return 1;
}
