#pragma once

#include <stdbool.h>

#define BOARD_WIDTH  7
#define BOARD_HEIGHT 6

struct Board;
struct Token;

struct Board * board_init(void);
void board_print(const struct Board * board);
bool board_insert_token(struct Board * board, const struct Token * token, short column);
bool board_is_full(const struct Board * board);
