#pragma once

#include "token.h"

struct Player;

struct Player * player_init(const char * name, enum TokenColor color);
short player_get_column(const struct Player * player);
const struct Token * player_get_token(const struct Player * player);
