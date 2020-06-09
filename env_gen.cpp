#include "env_gen.h"
#include "treeClass.h"

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
}

void env_gen::tick(sprite_params** data, int width, int height) {
	int pressure_interval = 20000;
	if (init) {
		pressure_exec = int(win::GetTickCount()) + pressure_interval;
		init = false;
}	//tam gdzie nullptr ma byc jakies pole, inaczej jest address violation
	//onlyTreeDeamon->addTree(*(new Tree(nullptr, 2, 1, 3)));
	if (abs(pressure_exec) <= abs(int(win::GetTickCount()))) {
		std::cout << "tick ";
		//onlyTreeDeamon->treeControl();
	pressure_exec = int(win::GetTickCount()) + pressure_interval;
	}

}
