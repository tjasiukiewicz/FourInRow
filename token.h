#pragma once

#include "token_color.h"

struct Token {
    enum TokenColor color;
    char repr;
};

struct Token token_init(enum TokenColor color);
char token_get_repr(const struct Token * token);
enum TokenColor token_get_color(const struct Token * token);
