#pragma once
#include "Core.h"


class env_pressure {
public:
	void generate_pressure(sprite_params** data, int width, int height);

	//TODO: Add optional parameters
	void regenerate_pressure(sprite_params** data, int width, int height, int iterations = NULL);

};