#include "numtostr.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

void test_range(void) {
	const char * result = numtostr(0);
	assert(strcmp(result, "zero") == 0);
	result = numtostr(100);
	assert(strcmp(result, "sto") == 0);
	result = numtostr(101);
	assert(strcmp(result, "ERROR") == 0);
}

void test_0_10(void) {
}

int main(void) {
	test_range();
	test_0_10();
	return 0;
}
