#pragma once

#include <cmath>
#include <random>

#include "Core.h"

struct sprite_params;

class env_temperature
{
	const int min_temp = -10;
	const int max_temp = 35;
	const float change_percent = 0.2; //from range <0, 1)

public:
	void generate_temperature(sprite_params** data, int width, int height);
};

