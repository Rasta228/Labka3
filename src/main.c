#include "board_start.h"
#include "board_print_plain.h"
#include "board.h"
int main() {
    char deck[8][8];
    initDeck(deck);
    while(1) {
        printDeck(deck);
        makeMove(deck);
    }
}
