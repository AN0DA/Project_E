/// \file
/// \brief Source file for env_biomes
/// \details Source file for env_biomes environment parameter. Sets the biome of every tile.
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1

#include "env_biomes.h"

/// \brief Script setting the biome af every tile
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1
///
///Biome is generated based on tiles water status, temperature and humidity
///Full biome parameter table in core.h 
void env_biomes::generate_biomes(sprite_params** data, int width, int height) {
	Biomes b;
	for (int i = 0; i <= height; i++) {
		for (int j = 0; j <= width; j++) {
			double humidity = data[i][j].getHumidity();
			double temperature = data[i][j].get_temperature();
			if (data[i][j].isWater()) {
				if (temperature >= 0) {
					data[i][j].setBiome(Biomes::water);
					//std::cout << "water"<< " ";
				}
				else {
					data[i][j].setBiome(Biomes::ice);
					//std::cout << "ice"<< " ";
				}
			}


			else if (temperature >= 25) {
				if (humidity >= 90) {
					data[i][j].setBiome(Biomes::swamp);
					//std::cout << "swamp" << " ";
				}
				else if (humidity > 75) {
					data[i][j].setBiome(Biomes::rainforest);
					//std::cout << "rainforest" << " ";
				}
				else if (humidity < 20) {
					data[i][j].setBiome(Biomes::desert);
					//std::cout << "desert" << " ";
				}
				else {
					data[i][j].setBiome(Biomes::savanna);
					//std::cout << "savanna" << " ";
				}
			}
			else if (temperature >= 1) {
				data[i][j].setBiome(Biomes::grassland);
				//std::cout << "grassland" << " ";
			}
			else {
				data[i][j].setBiome(Biomes::snow);
				//std::cout << "snow" << " ";
			}
			//Debug printing 
			//std::cout << data[i][j].getBiome()<<" ";
		}
		//Debug printing 
		//std::cout << std::endl;
	}
}