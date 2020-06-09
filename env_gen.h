#pragma once

#include "Core.h"
#include "env_temperature.h"
#include "env_humidity.h"
#include "env_biomes.h"
#include "env_pressure.h"
#include "treeClass.h"

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

	int _width;
	int _height;
	sprite_params** _data;


	//tick counters
	bool init = true;
	int pressure_exec;

public:
	void generate_environment(sprite_params** data, int width, int height);
	void tick(sprite_params** data, int width, int height, TreeDaemon* mainTreeDaemon, sf::RenderWindow* window);

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
