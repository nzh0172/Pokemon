#include "chance.h"
#include <random>

int randomInRange(int start, int end) {
	return start + (rand() % end);
}

