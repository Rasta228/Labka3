#include <stdio.h>

void printDeck(char deck[8][8]) {
    for (int number = 0; number < 8; ++number) {
        for (int letter = 0; letter < 8; ++letter) {

            printf("%c ",deck[number][letter]);
        }
        printf("\n");
    }
}
int main() {
    char deck[8][8];
    printDeck(deck);
}