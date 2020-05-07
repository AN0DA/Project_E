#pragma once

#include "Core.h"
#include "env_temperature.h"
#include <iostream>

struct sprite_params;

class env_gen
{
	bool generate_temperature = true;

public:
	void generate_environment(sprite_params** data, int width, int height);
};
