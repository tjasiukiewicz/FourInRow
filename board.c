#include "board.h"
#include "token.h"
#include "board_displayer.h"
#include <string.h>
#include <stdlib.h>
#include <assert.h>

/* column normalized to index */
inline static bool try_drop_to_first_row(struct Board * board, const struct Token * token_ptr, unsigned column);
/* column normalized to index */
inline static void token_gravity(struct Board * board, short column);
/* column normalized to index */
inline static void token_gravity(struct Board * board, short column);
void swap_token_ptr(const struct Token ** t1, const struct Token ** t2);

struct Board {
    const struct Token * fields[BOARD_HEIGHT][BOARD_WIDTH];
};

static struct Board board;

struct Board * board_init(void) {
    memset(board.fields, (int)NULL, BOARD_WIDTH * BOARD_HEIGHT * sizeof(struct Token *));
    return &board;
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

bool board_is_full(const struct Board * board) {
    bool answer = true;
    for(unsigned col = 0; col < BOARD_WIDTH; ++col) {
        if(board->fields[BOARD_HEIGHT - 1][col] == NULL) {
            answer = false;
            break;
        }
    }
    return answer;
}

void board_accept(const struct Board * board) {
    int data[BOARD_WIDTH * BOARD_HEIGHT];
    for(unsigned row = 0; row < BOARD_HEIGHT; ++row) {
        for(unsigned col = 0; col < BOARD_WIDTH; ++col) {
            const struct Token * field = board->fields[row][col];
            data[row * BOARD_WIDTH + col] = (field == NULL ? 0 : token_get_color(field) == Red ? 1: 2);
        }
    }

    board_displayer_visit(data);
}

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

inline static void token_gravity(struct Board * board, short column) {
    unsigned row = BOARD_HEIGHT - 1;
    while(--row) {
        if(board->fields[row][column]) {
            break;
        }
        swap_token_ptr(&(board->fields[row][column]), &(board->fields[row + 1][column]));
    }
}
