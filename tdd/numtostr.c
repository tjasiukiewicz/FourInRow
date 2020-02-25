#include "numtostr.h"

const char * numtostr(unsigned value) {
	if(value == 0) {
		return "zero";
	} else if(value == 100) {
		return "sto";
	}
	return "ERROR";
}
