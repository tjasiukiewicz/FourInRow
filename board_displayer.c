#include "board_displayer.h"
#include "board.h"

struct BoardDisplayer {
    int fields[BOARD_HEIGHT][BOARD_WIDTH];
};

static struct BoardDisplayer displayer;

struct BoardDisplayer * board_displayer_init(void) {
    return &displayer;
}

void board_displayer_visit(int * tab) {
    for(unsigned row = 0; row < BOARD_HEIGHT; ++row) {
        for(unsigned col = 0; col < BOARD_WIDTH; ++col) {
            displayer.fields[row][col] = tab[row * BOARD_WIDTH + col];
        }
    }
}

void board_displayer_print(void) {
}
