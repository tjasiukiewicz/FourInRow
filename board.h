#pragma once

#include <stdbool.h>

#define BOARD_WIDTH  7
#define BOARD_HEIGHT 6

struct Board;
struct Token;
struct BoardDisplayer;

struct Board * board_init(void);
bool board_insert_token(struct Board * board, const struct Token * token, short column);
bool board_is_full(const struct Board * board);
void board_accept(const struct Board * board);
