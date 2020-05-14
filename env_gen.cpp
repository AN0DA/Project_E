#include "env_gen.h"

void env_gen::generate_environment(sprite_params** data, int width, int height) {
	int w = width;
	int h = height;
	sprite_params** d = data;

	env_temperature temperature;

	if (generate_temperature)
		temperature.generate_temperature(d, w, h);
}
