#pragma once

#include <cmath>
#include <random>
#include "Core.h"

class env_humidity {
	const unsigned short min_humidity = 0;
	const unsigned short max_humidity = 100;

public:
	void generate_humidity(sprite_params** data, int width, int height);
	void generate_desert(sprite_params** data, int width, int height, int coordX, int coordY);
	void generate_lake(sprite_params** data, int coordX, int coordY, int radius);
	void generate_river(sprite_params** data, int width, int height, int coordX, int coordY, int river_width,int river_turn);
};