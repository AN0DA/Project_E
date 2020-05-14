#pragma once
#include "Core.h"
#include "env_temperature.h"
#include "env_humidity.h"

class env_gen
{
	bool generate_temperature = true;
	bool generate_humidity = true;

public:
	void generate_environment(sprite_params** data, int width, int height);
};
