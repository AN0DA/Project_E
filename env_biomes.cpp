#include "env_biomes.h"

void env_biomes::generate_biomes(sprite_params** data, int width, int height) {
	for (int i = 0; i <= height; i++) {
		for (int j = 0; j <= width; j++) {
			humidity = data[i][j].getHumidity();
			temperature = data[i][j].get_temperature();
			if (humidity == 100) {
				if (temperature >= 0) {
					data[i][j].setBiome(water);
				}
				else {
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