#pragma once

#include "Core.h"
#include "env_temperature.h"
#include "env_humidity.h"
#include "env_biomes.h"
#include "env_pressure.h"

#include <cmath>

namespace win {
#include <windows.h>
}

class env_gen
{
	bool generate_temperature = true;
	bool generate_humidity = true;
	bool generate_biomes = true;
	bool generate_pressure = true;


	//tick counters
	bool init = true;
	int pressure_exec;

public:
	void generate_environment(sprite_params** data, int width, int height);

	void tick();
};
