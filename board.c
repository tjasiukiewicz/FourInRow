#include "board.h"
#include <stdlib.h>

#define BOARD_WIDTH  7
#define BOARD_HEIGHT 6

struct Board {
    struct Token * fields[BOARD_HEIGHT][BOARD_WIDTH];
};

static struct Board board;

struct Board * board_init(void) {
    // Inicjalizacja null
    for(unsigned row = 0; row < BOARD_HEIGHT; ++row) {
        for(unsigned col = 0; col < BOARD_WIDTH; ++col) {
            board.fields[row][col] = NULL;
        }
    }
    return &board;
}

void board_print(const struct Board * board) {
    // Wyświetlanie stanu board
    (void) board;
}

bool board_insert_token(struct Board * board, const struct Token * token, short column) {
    // Obsługa wrzucenia token'u
    return true;

    (void) board;
    (void) token;
    (void) column;
    (void) board;
}
