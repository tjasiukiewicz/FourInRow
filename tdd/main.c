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
	const char * result = numtostr(0);
	assert(strcmp(result, "zero") == 0);
	result = numtostr(1);
	assert(strcmp(result, "jeden") == 0);
	result = numtostr(2);
	assert(strcmp(result, "dwa") == 0);
	result = numtostr(3);
	assert(strcmp(result, "trzy") == 0);
	result = numtostr(4);
	assert(strcmp(result, "cztery") == 0);
	result = numtostr(5);
	assert(strcmp(result, "pięć") == 0);
	result = numtostr(6);
	assert(strcmp(result, "sześć") == 0);
	result = numtostr(7);
	assert(strcmp(result, "siedem") == 0);
	result = numtostr(8);
	assert(strcmp(result, "osiem") == 0);
	result = numtostr(9);
	assert(strcmp(result, "dziewięć") == 0);
	result = numtostr(10);
	assert(strcmp(result, "dziesięć") == 0);
}

void test_rounded_10(void) {
	const char * result = numtostr(10);
	assert(strcmp(result, "dziesięć") == 0);
	result = numtostr(20);
	assert(strcmp(result, "dwadzieścia") == 0);
	result = numtostr(30);
	assert(strcmp(result, "trzydzieści") == 0);
	result = numtostr(40);
	assert(strcmp(result, "czterdzieści") == 0);
	result = numtostr(50);
	assert(strcmp(result, "pięćdziesiąt") == 0);
	result = numtostr(60);
	assert(strcmp(result, "sześćdziesiąt") == 0);
	result = numtostr(70);
	assert(strcmp(result, "siedemdziesiąt") == 0);
	result = numtostr(80);
	assert(strcmp(result, "osiemdziesiąt") == 0);
	result = numtostr(90);
	assert(strcmp(result, "dziewięćdziesiąt") == 0);
}

void test_11_19(void) {
	const char * result = numtostr(11);
	assert(strcmp(result, "jedenaście") == 0);
	result = numtostr(12);
	assert(strcmp(result, "dwanaście") == 0);
	result = numtostr(13);
	assert(strcmp(result, "trzynaście") == 0);
	result = numtostr(14);
	assert(strcmp(result, "czternaście") == 0);
	result = numtostr(15);
	assert(strcmp(result, "piętnaście") == 0);
	result = numtostr(16);
	assert(strcmp(result, "szesnaście") == 0);
	result = numtostr(17);
	assert(strcmp(result, "siedemnaście") == 0);
	result = numtostr(18);
	assert(strcmp(result, "osiemnaście") == 0);
	result = numtostr(19);
	assert(strcmp(result, "dziewiętnaście") == 0);
}

void test_not_round_10(void) {
	const char * result = numtostr(21);
	assert(strcmp(result, "dwadzieścia jeden") == 0);
	result = numtostr(42);
	assert(strcmp(result, "czterdzieści dwa") == 0);
	result = numtostr(73);
	assert(strcmp(result, "siedemdziesiąt trzy") == 0);
	result = numtostr(94);
	assert(strcmp(result, "dziewięćdziesiąt cztery") == 0);
	result = numtostr(35);
	assert(strcmp(result, "trzydzieści pięć") == 0);
	result = numtostr(56);
	assert(strcmp(result, "pięćdziesiąt sześć") == 0);
	result = numtostr(87);
	assert(strcmp(result, "osiemdziesiąt siedem") == 0);
	result = numtostr(88);
	assert(strcmp(result, "osiemdziesiąt osiem") == 0);
	result = numtostr(99);
	assert(strcmp(result, "dziewięćdziesiąt dziewięć") == 0);
}


int main(void) {
	test_range();
	test_0_10();
	test_11_19();
	test_rounded_10();
	test_not_round_10();
	return 0;
}
