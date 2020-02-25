#include "game.h"

int main(void) {
    struct Game * game = game_init();
    game_run(game);

    return 0;
}
