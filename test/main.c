#define CTEST_MAIN

#include <board_read.h>

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

int main(int argc, const char** argv) {
    return ctest_main(argc, argv);
}
