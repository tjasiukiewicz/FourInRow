#include "board_displayer.h"
#include "settings.h"
#include <stdio.h>
#include <string.h>

inline static void show_column_names(void);
inline static void show_row_separator(void);
inline static void show_row(unsigned row);

struct BoardDisplayer {
    int fields[BOARD_HEIGHT][BOARD_WIDTH];
};

static struct BoardDisplayer displayer;

struct BoardDisplayer * board_displayer_init(void) {
    memset(displayer.fields, 0, BOARD_WIDTH * BOARD_HEIGHT * sizeof(int));
    return &displayer;
}

void board_displayer_visit(int * tab) {
    memcpy(displayer.fields, tab, BOARD_WIDTH * BOARD_HEIGHT * sizeof(int));
}

void board_displayer_print(void) {
    show_column_names();
    unsigned row = BOARD_HEIGHT;
    while(--row) {
        show_row_separator();
        show_row(row);
    }
    show_row_separator();
    show_column_names();
}

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

inline static void show_row(unsigned row) {
    static const char repr[] = " XO";
    for(unsigned col = 0; col < BOARD_WIDTH; ++col) {
        int field = displayer.fields[row][col];
        char c = (field > 2 ? '?': repr[field]);
        printf("|%c", c);
    }
    puts("|");
}

