#include "Random.h"
#include <ctime>

// time sets time at runtime as the seed
std::mt19937 Random::random(time(0));

// min and max inclusive, but how can you avoid generating same number? Need distinct randoms
int Random::Int(int min, int max) {
	std::uniform_int_distribution<int> dist(min, max);
	return dist(random);
}

float Random::Float(float min, float max) {
	std::uniform_real_distribution<float> dist(min, max);
	return dist(random);
}