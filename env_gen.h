#pragma once

#include "Core.h"
#include "env_temperature.h"
#include "env_humidity.h"
#include "env_biomes.h"
#include "env_pressure.h"
#include "treeClass.h"
#include "map_graphics.h"

#include <cmath>


class env_gen
{
	bool generate_temperature = true;
	bool generate_humidity = true;
	bool generate_biomes = true;
	bool generate_pressure = true;
	bool generate_neighbours = true;

	int _width;
	int _height;
	sprite_params** _data;

	//tick counters
	int temperature_mix_exec = 0;

public:
	/// \brief Function supervising the generation of environmental parameters.
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	void generate_environment(sprite_params** data, int width, int height);

	/// \brief function handling tick 
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	/// \param mainTreeDaemon Handler of all trees in app
	/// \param window window for draw
	/// \param g map_graphics to redraw biomes
	/// \param scale_width double for sizing up textures
	/// \param scale_height double for sizing up textures
	void tick(sprite_params** data, int width, int height, TreeDaemon* mainTreeDaemon, sf::RenderWindow* window, map_graphics* g, double scale_width, double scale_height);

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
