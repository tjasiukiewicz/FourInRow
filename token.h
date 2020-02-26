#pragma once

#include "settings.h"

#define X(en, enum_name, c) en,
enum TokenColor { COLORS };
#undef X

struct Token {
    enum TokenColor color;
    char repr;
};

struct Token token_init(enum TokenColor color);
char token_get_repr(const struct Token * token);
enum TokenColor token_get_color(const struct Token * token);
