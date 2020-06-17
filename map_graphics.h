#pragma once
/// \headerfile
/// \brief Header file for generationg map graphics
/// \details Header file for generating map graphics
/// \author Konstanty Kordas
/// \date 9.06.2020
/// \version 0.1
#include <SFML\Graphics\RenderWindow.hpp>
#include "Core.h"


class map_graphics {
	/// \class map_graphics map_graphics.h
	/// \brief Class related to generating map graphics
	/// \author Konstanty Kordas
	sf::RenderWindow* window;
	///window of the program
	double scale_height;
	/// height of the window program (in px)
	double scale_width;
	/// width of the window program (in px)
	sprite_params** field;
	/// grid on which generation is based
	int field_height;
	/// height of the grid 
	int field_width;
	/// width of the grid 
	sf::Texture water;
	/// texture of water
	sf::Texture ice;
	/// texture of ice
	sf::Texture swamp;
	/// texture of swamp
	sf::Texture rainforest;
	/// texture of rainforrest
	sf::Texture desert;
	/// texture of desert
	sf::Texture savanna;
	/// texture of savanna
	sf::Texture grassland;
	/// texture of grassland
	sf::Texture snow;
	/// texture of snow
	sf::Texture error_texture;
	/// error texture, loaded when no other texture found
public:
	/// map_graphics class constructor
	///
	/// \param window window of the program
	/// \param window_height height of the window program (in px)
	/// \param window_width width of the window program (in px)
	/// \param field grid on which generation is based
	/// \param field_height height of the grid 
	/// \param field_width width of the grid 
	map_graphics(sf::RenderWindow* window, double scale_height, double scale_width, sprite_params** field, int field_height, int field_width);

	/// fuction that loads textures from files and logs in console success and failure
	/// loads water,ice,swamp,rainforrest,desert,savanna,grassland,snow and error texture from "{texture_name}.jpg" files
	void load_textures();

	/// function that draws the map based on the biome parameter of the blocks on grid
	/// textures are loaded by load_textures function called in constructor
	void biome_map();


	/// fuction that draws map based on the temperature of the blocks on the grid
	/// color goes from red to yellow to green to blue (hot to cold)
	void heat_map();


	/// fuction that draws map based on the humidity of the blocks on the grid
    /// color is grey for water and goes from blue to green to yellow (wet to dry)
	void water_map();

	/// function that draws map based on the pressure on the blocks of the grid
	void pressure_map();

};