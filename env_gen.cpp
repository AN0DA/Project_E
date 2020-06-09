#include "env_gen.h"
#include <iostream>
#include "treeClass.h"


void create_neighbours(sprite_params** data, int width, int height)
{
	for (int j = 0; j <= width; j++)
	{
		for (int i = 0; i <= height; i++)
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

void env_gen::generate_environment(sprite_params** data, int width, int height) {
	_width = width;
	_height - height;
	_data = data;
	
	int w = width;
	int h = height;
	sprite_params** d = data;

	env_temperature temperature;
	env_humidity humidity;
	env_pressure pressure;
	env_biomes biomes;


	if (generate_temperature) {
		temperature.generate_temperature(d, w, h);
	}
	if (generate_humidity) {
		humidity.generate_humidity(d, w, h);
	}
	if (generate_biomes) {
		biomes.generate_biomes(d, w, h);
	}
	if (generate_pressure) {
		pressure.generate_pressure(d, w, h);
	}
	create_neighbours(d, w, h);
}

void env_gen::tick(sprite_params** data, int width, int height, TreeDaemon* mainTreeDaemon) {
	int pressure_interval = 100;
	if (init) {
		pressure_exec = int(win::GetTickCount()) + pressure_interval;
		init = false;
	}	//tam gdzie nullptr ma byc jakies pole, inaczej jest address violation
	if (abs(pressure_exec) <= abs(int(win::GetTickCount()))) {
		std::cout << "tick ";
		mainTreeDaemon->treeControl();
	pressure_exec = int(win::GetTickCount()) + pressure_interval;
	}

}


