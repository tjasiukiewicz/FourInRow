#include <stdio.h>
#include "ex.h"
#include "foo.h"

int main(void) {
    struct Foo f = foo();
    printf("%d\n", f.data);
    return 0;
}
