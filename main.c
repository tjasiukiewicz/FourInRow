#include "board.h"
#include "token.h"

int main(void) {
    /* US1 */
    struct Board * board = board_init();
    board_print(board);
    /* US2 */
    struct Token token1 = token_init(Red);
    struct Token token2 = token_init(Yellow);
    board_insert_token(board, &token1, 1);
    board_insert_token(board, &token2, 1);
    while(board_insert_token(board, &token1, 7)) {}
    board_print(board);
    return 0;
}
