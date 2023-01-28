#pragma once
/// \headerfile
/// \brief Header file for env_biomes
/// \details Header file for env_biomes environment parameter. Sets the biome of every tile.
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1
#include "Core.h"

class env_biomes {
	/// \class env_biomes env_biomes.h
	/// \brief Class related to setting the biome of all tiles on the grid
	/// \author Konstanty Kordas


public:
	/// Fuction that goes through every tile on the grid and sets its biome based on tiles temperature and humidity
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	void generate_biomes(sprite_params** data, int width, int height);
};