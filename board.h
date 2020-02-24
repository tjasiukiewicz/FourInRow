#pragma once

#include <stdbool.h>

struct Board;
struct Token;

struct Board * board_init(void);
void board_print(const struct Board * board);
bool board_insert_token(struct Board * board, const struct Token * token, short column);
