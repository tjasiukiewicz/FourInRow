#include "board.h"
#include "token.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

#define BOARD_WIDTH  7
#define BOARD_HEIGHT 6

struct Board {
    const struct Token * fields[BOARD_HEIGHT][BOARD_WIDTH];
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
        const struct Token * token_ptr = board->fields[row][col];
        printf("|%c", token_ptr == NULL ? ' ': token_get_repr(token_ptr));
    }
    puts("|");
}

/* column normalized to index */
inline static bool try_drop_to_first_row(struct Board * board, const struct Token * token_ptr, unsigned column) {
    bool result = true;
    if(board->fields[BOARD_HEIGHT - 1][column] == NULL) {
        board->fields[BOARD_HEIGHT - 1][column] = token_ptr;
    } else {
        result = false;
    }
    return result;
}

void swap_token_ptr(const struct Token ** t1, const struct Token ** t2) {
    const struct Token * tmp_ptr = *t1;
    *t1 = *t2;
    *t2 = tmp_ptr;
}

/* column normalized to index */
inline static void token_gravity(struct Board * board, short column) {
    unsigned row = BOARD_HEIGHT - 1;
    while(--row) {
        if(board->fields[row][column]) {
            break;
        }
        swap_token_ptr(&(board->fields[row][column]), &(board->fields[row + 1][column]));
    }
}

static struct Board board;

struct Board * board_init(void) {
    memset(board.fields, (int)NULL, BOARD_WIDTH * BOARD_HEIGHT * sizeof(struct Token *));
    return &board;
}

void board_print(const struct Board * board) {
    show_column_names();
    unsigned row = BOARD_HEIGHT;
    while(--row) {
        show_row_separator();
        show_row(board, row);
    }
    show_row_separator();
    show_column_names();
}

bool board_insert_token(struct Board * board, const struct Token * token, short column) {
    assert((column > 0) && (column < (BOARD_WIDTH + 1)));

    /* Normalize column to C index */
    --column;

    bool result = true;
    if(! try_drop_to_first_row(board, token, column)) {
        result = false;
    } else {
        token_gravity(board, column);
    }
    return result;
}
