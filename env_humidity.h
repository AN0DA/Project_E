#pragma once
/// \headerfile
/// \brief Header file for env_humidity
/// \details Header file for env_humidity environment parameter. Generates river, lakes and humidity around them.
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1

#include <cmath>
#include <random>
#include "Core.h"

///
class env_humidity {
	/// \class env_humidity env_humidity.h
	/// \brief Class related to environment water and humidity simulation.
	/// \author Konstanty Kordas
	const unsigned short min_humidity = 0; ///< Lowest humidity that can be generated NOT IMPLEMENTED YET
	const unsigned short max_humidity = 100; ///< Highest humidity that can be generated NOT IMPLEMENTED YET

public:
	/// Fuction that calls all other generation functions and sets up thier parameters
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	void generate_humidity(sprite_params** data, int width, int height);


	/// Fuction that generates tiles, where humidity is set to 10 to allow for desert generation
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	/// \param coordX X axis (width) index of the beginnig of desert
	/// \param coordY Y axis (height) index of the beginnig of desert
	void generate_desert(sprite_params** data, int width, int height, int coordX, int coordY);


	/// Fuction that generates a circular shape lake of water tiles
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	/// \param coordX X axis (width) index of the middle point of lake
	/// \param coordY Y axis (height) index of the middle point of lake
	/// \param radius the radius of the generated lake
	void generate_lake(sprite_params** data, int width, int height, int coordX, int coordY, int radius);


	/// Fuction that generates a river flowing from top to bottom of the grid, with a turn in a middle
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	/// \param coordX X axis (width) index of the top starting point of the river
	/// \param coordY Y axis (height) index of the top starting point of the river
	/// \param river_width additional width of a river beyond the base 1
	/// \param river_turn Y axis (height) index of the turn of the river
	void generate_river(sprite_params** data, int width, int height, int coordX, int coordY, int river_width,int river_turn);


	/// Fuction that adds humidity to all tiles in a circular shape 
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	/// \param coordX X axis (width) index of the humidity source
	/// \param coordY Y axis (height) index of the humidity source
	/// \param radius the radius of the humidity range
	void circle_humidity(sprite_params** data, int width, int height, int coordX, int coordY, int radius);


	/// Fuction that creates a water tile and calls circle humidty on that tile
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	/// \param coordX X axis (width) index of the water tile
	/// \param coordY Y axis (height) index of the water tile
	/// \param humidity_reach the radius of the humidity range
	void create_water_tile(sprite_params** data, int width, int height, int coordX, int coordY, int humidity_reach);

};