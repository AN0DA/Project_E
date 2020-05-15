#include "env_gen.h"

void env_gen::generate_environment(sprite_params** data, int width, int height) {
	int w = width;
	int h = height;
	sprite_params** d = data;

	env_temperature temperature;

	env_humidity humidity;

	env_biomes biomes;

	if (generate_temperature) {
		temperature.generate_temperature(d, w, h);
	}
	std::cout << "TEMP";
	if (generate_humidity) {
		humidity.generate_humidity(d, w, h);
	}
	std::cout << "HUMIDITY";
	if (generate_biomes) {
		biomes.generate_biomes(d, w, h);
		std::cout << "BIOMES";
	}


}
