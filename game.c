#include "game.h"
#include "board.h"
#include "player.h"
#include <stdio.h>

struct Game {
    struct Board * board;
    const struct Player * current_player;
    const struct Player * next_player;
};

static struct Game game;

static inline void swap_players(struct Game * game) {
    const struct Player * tmp = game->current_player;
    game->current_player = game->next_player;
    game->next_player = tmp;
}

struct Game * game_init(void) {
    game.board = board_init();
    game.current_player = player_init("Adam", Red);
    game.next_player = player_init("Eve", Yellow);
    return &game;
}

void game_run(struct Game * game) {
    board_print(game->board);
    while(! board_is_full(game->board)) {
        short column = player_get_column(game->current_player);
        if(! board_insert_token(game->board, player_get_token(game->current_player), column)) {
            fprintf(stderr, "Column is full. Try again.\n");
            continue;
        }
        swap_players(game);

        board_print(game->board);
    }
}
