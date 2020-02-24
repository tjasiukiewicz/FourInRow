#pragma once

enum TokenColor {
    Red,
    Yellow
};

struct Token {
    enum TokenColor color;
    char repr;
};


struct Token token_init(enum TokenColor color);
char token_get_repr(const struct Token * token);
