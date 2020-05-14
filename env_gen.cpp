#include "env_gen.h"

void env_gen::generate_environment(sprite_params** data, int width, int height) {
	int w = width;
	int h = height;
	sprite_params** d = data;

	env_temperature temperature;

	env_humidity humidity;

	if (generate_temperature) {
		temperature.generate_temperature(d, w, h);
	}
	if (generate_humidity) {
		humidity.generate_humidity(d, w, h);
	}


}
int humidity;
int temperature;
void generate_biomes(sprite_params** data, int width, int height) {
	for (int i = 0; i <= height; i++) {
		for (int j = 0; j <= width; j++) {
			humidity = data[i][j].getHumidity();
			temperature = data[i][j].get_temperature();
			if (humidity == 100) {
				if (temperature >= 0) {
					data[i][j].setBiome(water);
				}
				else
				{
					data[i][j].setBiome(ice);
				}
			}
			else if (temperature >= 25) {
				if (humidity > 80) {
					data[i][j].setBiome(rainforest);
				}
				else if (humidity < 20) {
					data[i][j].setBiome(desert);
				}
				else {
					data[i][j].setBiome(savanna);
				}
			}
			else if (temperature >= 1) {
				data[i][j].setBiome(grassland);
			}
			else {
				data[i][j].setBiome(snow);
			}
		}
	}
}