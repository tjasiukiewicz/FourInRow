#include "token.h"
#include <assert.h>

#define X(en, enum_name, c) c,
static char token_repr[] = { COLORS };
#undef X

struct Token token_init(enum TokenColor color) {
    assert(color < 2);
    char c = token_repr[color];
    return (struct Token){ .color = color, .repr = c};
}

char token_get_repr(const struct Token * token) {
    return token->repr;
}

enum TokenColor token_get_color(const struct Token * token) {
    return token->color;
}
