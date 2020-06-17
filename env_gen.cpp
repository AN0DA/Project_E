#include "env_gen.h"
#include <iostream>
#include "treeClass.h"

/// Fuction that generates neighbours
/// Each block has 2,3 or 4 neighbours
///
/// \param data sprite_params array passed from main
/// \param width sprite_params array width
/// \param height sprite_params array height
void create_neighbours(sprite_params** data, int width, int height)
{
	for (int j = 0; j <= height; j++)
	{
		for (int i = 0; i <= width; i++)
		{
			if (j == 0 && i == 0)
			{
				data[i][j].neighbours = new sprite_params * [2]{ &data[i + 1][j], &data[i][j + 1] };
				data[i][j].neighbour_count = 2;
			}
			else if (j == 0 && i == height)
			{
				data[i][j].neighbours = new sprite_params * [2]{ &data[i - 1][j], &data[i][j + 1] };
				data[i][j].neighbour_count = 2;
			}
			else if (j == width && i == 0)
			{
				data[i][j].neighbours = new sprite_params * [2]{ &data[i + 1][j], &data[i][j - 1] };
				data[i][j].neighbour_count = 2;
			}
			else if (j == width && i == height)
			{
				data[i][j].neighbours = new sprite_params * [2]{ &data[i - 1][i], &data[i][j - 1] };
				data[i][j].neighbour_count = 2;
			}
			else if (i == 0)
			{
				data[i][j].neighbours = new sprite_params * [3]{ &data[i][j - 1], &data[i][j + 1], &data[i + 1][j] };
				data[i][j].neighbour_count = 3;
			}
			else if (j == 0)
			{
				data[i][j].neighbours = new sprite_params * [3]{ &data[i - 1][j], &data[i + 1][j], &data[i][j + 1] };
				data[i][j].neighbour_count = 3;
			}
			else if (i == height)
			{
				data[i][j].neighbours = new sprite_params * [3]{ &data[i][j - 1], &data[i][j + 1], &data[i - 1][j] };
				data[i][j].neighbour_count = 3;
			}
			else if (j == width)
			{
				data[i][j].neighbours = new sprite_params * [3]{ &data[i - 1][j], &data[i + 1][j], &data[i][j - 1] };
				data[i][j].neighbour_count = 3;
			}
			else
			{
				data[i][j].neighbours = new sprite_params * [4]{ &data[i - 1][j], &data[i + 1][j], &data[i][j - 1], &data[i][j + 1] };
				data[i][j].neighbour_count = 4;
			}
		}
	}
}

/// \brief Function supervising the generation of environmental parameters
/// \author Mikolaj Kaczmarek
/// \author Konstanty Kordas
/// \date 28.06.2020
/// \version 1.40
///
/// In this method all enivronment generators are called. Using bools (generate_temperature, generate_humidity, generate_bioms, generate_pressure and generate_naighbours) you can easly turn them on and off.
void env_gen::generate_environment(sprite_params** data, int width, int height) {
	_width = width;
	_height = height;
	_data = data;
	
	env_temperature temperature;
	env_humidity humidity;
	env_pressure pressure;
	env_biomes biomes;

	if (generate_temperature) {
		temperature.generate_temperature(data, width, height);
	}
	if (generate_humidity) {
		humidity.generate_humidity(data, width, height);
	}
	if (generate_biomes) {
		biomes.generate_biomes(data, width, height);
	}
	if (generate_pressure) {
		pressure.generate_pressure(data, width, height);
	}
	if (generate_neighbours) {
		create_neighbours(data, width, height);
	}
}

/// \brief Global tick engine
/// \author Mikolaj Kaczmarek
/// \author Konstanty Kordas
/// \author Bruno Murek
/// \date 18.06.2020
/// \version 1.34
///
/// This funcion is called 30 times per second and call periodically other time fuctions like mix_temperature or redraw map.
void env_gen::tick(sprite_params** data, int width, int height, TreeDaemon* mainTreeDaemon, sf::RenderWindow* window, map_graphics* g, double scale_width, double scale_height) {
	int temperature_mix_interval = 1;
	bool redraw = false;
	env_temperature temperature;

	//std::cout << "tick " << std::endl;;
	mainTreeDaemon->treeControl();
	if (mainTreeDaemon->checkChange()) {
		// check if needs to redraw any trees
		std::cout << "TREE change" << std::endl;
		redraw = true;
	}

	if (temperature_mix_exec == temperature_mix_interval) {
		temperature.mix_temperature(data, width, height);
		temperature_mix_exec = 0;
		redraw = true;
	}
	else
		temperature_mix_exec++;

	if (redraw) {
		//redraw
		window->clear();
		g->biome_map();
		mainTreeDaemon->Change(window, scale_width, scale_height);
		window->display();
		redraw = false;
		std::cout << "redraw " << std::endl;
	}
}