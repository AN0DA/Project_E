#pragma once
#include "Core.h"
#include "env_temperature.h"
#include "env_humidity.h"
#include "env_biomes.h"
#include "env_pressure.h"

class env_gen
{
	bool generate_temperature = true;
	bool generate_humidity = true;
	bool generate_biomes = true;
	bool generate_pressure = true;

public:
	void generate_environment(sprite_params** data, int width, int height);

	void tick();
};
