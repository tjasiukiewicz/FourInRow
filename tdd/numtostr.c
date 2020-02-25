#include "numtostr.h"
#include <string.h>

const char * numtostr(unsigned value) {
	static char buff[64];
	static const char * num_str[] = {
		"zero", "jeden", "dwa", "trzy", "cztery", "pięć", "sześć", "siedem", "osiem", "dziewięć", "dziesięć",
		"jedenaście", "dwanaście", "trzynaście", "czternaście", "piętnaście", "szesnaście", "siedemnaście",
		"osiemnaście", "dziewiętnaście"
	};
	static const char * num_ten[] = {
		"ERROR", "dziesięć", "dwadzieścia", "trzydzieści", "czterdzieści", "pięćdziesiąt", "sześćdziesiąt",
		"siedemdziesiąt", "osiemdziesiąt", "dziewięćdziesiąt", "sto"
	};
	buff[0] = '\0';
	if(value > 100) {
		strcpy(buff, "ERROR");
	} else if(value < 20) {
		strcpy(buff, num_str[value]);
	} else if((value >= 20) && ((value % 10) == 0)) {
		strcpy(buff, num_ten[value / 10]);
	} else {
		strcpy(buff, num_ten[value / 10 ]);
		strcat(buff, " ");
		strcat(buff, num_str[value % 10]);
	}
	return buff;
}
