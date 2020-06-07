#include "env_gen.h"

void env_gen::generate_environment(sprite_params** data, int width, int height) {
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

void env_gen::tick() {
	int pressure_interval = 20000;

	if (init) {
		pressure_exec = int(win::GetTickCount()) + pressure_interval;
		init = false;
}

	if (abs(pressure_exec) <= abs(int(win::GetTickCount()))) {
		std::cout << "tick ";
	pressure_exec = int(win::GetTickCount()) + pressure_interval;
	}

}
