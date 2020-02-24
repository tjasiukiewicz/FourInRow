#include "board.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BOARD_WIDTH  7
#define BOARD_HEIGHT 6

struct Board {
    struct Token * fields[BOARD_HEIGHT][BOARD_WIDTH];
};

inline static void show_column_names(void) {
    for(unsigned i = 0; i < BOARD_WIDTH; ++i) {
        printf(" %d", i + 1);
    }
    putchar('\n');
}

inline static void show_row_separator(void) {
    for(unsigned i = 0; i < BOARD_WIDTH; ++i) {
        printf("+-");
    }
    puts("+");
}

inline static void show_row(const struct Board * board, unsigned row) {
    for(unsigned col = 0; col < BOARD_WIDTH; ++col) {
        printf("|%c", board->fields[row][col] == NULL ? ' ': '?');
    }
    puts("|");
}

static struct Board board;

struct Board * board_init(void) {
    // Inicjalizacja null
    memset(board.fields, (int)NULL, BOARD_WIDTH * BOARD_HEIGHT * sizeof(struct Token *));
    return &board;
}

void board_print(const struct Board * board) {
    show_column_names();
    for(unsigned row = 0; row < BOARD_HEIGHT; ++row) {
        show_row_separator();
        show_row(board, row);
    }
    show_row_separator();
    show_column_names();
}

bool board_insert_token(struct Board * board, const struct Token * token, short column) {
    // TODO: Obsługa wrzucenia token'u
    return true;

    (void) board;
    (void) token;
    (void) column;
    (void) board;
}
