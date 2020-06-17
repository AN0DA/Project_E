#pragma once

#include "Core.h"
#include "env_temperature.h"
#include "env_humidity.h"
#include "env_biomes.h"
#include "env_pressure.h"
#include "treeClass.h"
#include "map_graphics.h"

#include <cmath>

namespace win {
#include <windows.h>
}

class env_gen
{
	bool init_gen = true;
	bool generate_temperature = true;
	bool generate_humidity = true;
	bool generate_biomes = true;
	bool generate_pressure = true;

	//tick counters
	bool init_tick = true;
	int temperature_mix_exec;

public:
	int _width;
	int _height;
	sprite_params** _data;

	void generate_environment(sprite_params** data, int width, int height);
	void tick(sprite_params** data, int width, int height, TreeDaemon* mainTreeDaemon, sf::RenderWindow* window,map_graphics*g, double scale_width, double scale_height);

	int get_width() {
		return this->_width;
	};
	int get_height() {
		return this->_height;
	};
	void setData(sprite_params** newData) {
		this->_data = newData;
	};
	sprite_params** get_data() {
		return this->_data;
	};
};
