#ifndef BOARD_H
#define BOARD_H

void board(char deck[8][8]);
int check_move(char deck[8][8], int move[]);
int black_pwn(char deck[8][8], int move[]);
int white_pwn(char deck[8][8], int move[]);

#endif
