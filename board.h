#pragma once

#include <stdbool.h>

struct Token;

void board_init(void);
bool board_insert_token(const struct Token * token, short column);
bool board_is_full(void);
void board_accept(void);
