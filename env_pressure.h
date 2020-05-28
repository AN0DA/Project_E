#pragma once
#include "Core.h"


class env_pressure {
public:
	void generate_pressure(sprite_params** data, int width, int height);

	void regenerate_pressure(sprite_params** data, int width, int height, int iterations);

};