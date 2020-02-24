#include "board.h"

int main(void) {
    /* US1 */
    struct Board * board = board_init();
    board_print(board);
    return 0;
}
