#include "player.h"
#include "settings.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static inline void consume_chars(void);

struct Player {
    char name[32];
    struct Token token;
};

static struct Player players[2];
static unsigned player_count = 0;

struct Player * player_init(const char * name_, enum TokenColor color) {
    struct Player * my_player = &(players[player_count]);
    strcpy(my_player->name, name_);
    my_player->token = token_init(color);
    ++player_count;
    player_count %= 2;
    return my_player;
}

short player_get_column(const struct Player * player) {
    short column = 0;
    for(;;) {
        printf("Player: %s, plays: |%c|. Input column [1, %d]: ",
            player->name, token_get_repr(&(player->token)), BOARD_WIDTH);
        if(1 != scanf("%hd", &column)) {
            fprintf(stderr, "Input error. Try again.\n");
        } else if((column > 0) && (column <= BOARD_WIDTH)) {
            break;
        } else {
            fprintf(stderr, "Column out of range. Try again.\n");
        }
        consume_chars();
    }
    return column;
}

const struct Token * player_get_token(const struct Player * player) {
    return &(player->token);
}

static inline void consume_chars(void) {
    int c;
    while (((c = getchar()) != EOF) && (c != '\n')) {}
}

