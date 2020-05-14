#pragma once

#include "Core.h"

class env_biomes {
	int humidity;
	int temperature;
public:
	void generate_biomes(sprite_params** data, int width, int height);
};