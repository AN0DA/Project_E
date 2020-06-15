#include "env_gen.h"

void env_gen::generate_environment(sprite_params** data, int width, int height) {
	if (init_gen) {
		_width = width;
		_height = height;
		_data = data;
		init_gen = false;
	}


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
	int temperature_mix_interval = 20000;
	env_temperature temperature;


	if (init_tick) {
		temperature_mix_exec = int(win::GetTickCount()) + temperature_mix_exec;
		init_tick = false;
	}

	if (temperature_mix_exec <= int(win::GetTickCount())) {
		temperature.mix_temperature(data, width, height);
		temperature_mix_exec = int(win::GetTickCount()) + temperature_mix_interval;
	}
}