#define CTEST_MAIN

#include <board_read.h>
#include <board_start.h>
#include <board.h>

#include <ctest.h>

CTEST(Syntax, Correct) {
    int result = check_input("a2-a5");
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(Syntax, Incorrect) {
    int result = check_input("a2-a9");
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

CTEST(Black_pwn, Correct) {
    char deck[8][8];
    board_start(deck);
    char input[] = "a7-a5";
    int move[4];
    reformat_input(input, move);
    int result = black_pwn(deck, move);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(Black_pwn, Incorrect) {
    char deck[8][8];
    board_start(deck);
    char input[] = "a7-b6";
    int move[4];
    reformat_input(input, move);
    int result = black_pwn(deck, move);
    int expected = 1;
    ASSERT_EQUAL(expected, result);
}

int main(int argc, const char** argv) {
    return ctest_main(argc, argv);
}
