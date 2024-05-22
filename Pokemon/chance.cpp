#include "chance.h"
#include <random>

using namespace std;

int randomInRange(int start, int end) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distrib(start, end);
	return distrib(gen);
}


