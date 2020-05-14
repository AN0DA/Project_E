#pragma once

#include <cmath>
#include <random>
#include "Core.h"

class env_humidity {
	const unsigned short min_humidity = 0;
	const unsigned short max_humidity = 100;
	const float change_percent = 5;

public:
	void generate_humidity(sprite_params** data, int width, int height);
};