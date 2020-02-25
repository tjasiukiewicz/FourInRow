#include "token.h"

struct Token token_init(enum TokenColor color) {
    char c = (color == Red ? 'X': 'O');
    return (struct Token){ .color = color, .repr = c};
}

char token_get_repr(const struct Token * token) {
    return token->repr;
}

enum TokenColor token_get_color(const struct Token * token) {
    return token->color;
}
