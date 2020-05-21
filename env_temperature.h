#pragma once
#include <cmath>
#include <random>
#include "Core.h"

class env_temperature
{
	const int min_temp;
	const int max_temp;
	const double change_percent;

public:
	void generate_temperature(sprite_params** data, int width, int height);
};
