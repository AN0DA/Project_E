#pragma once
#include <SFML\Graphics\RenderWindow.hpp>
#include "Core.h"


class map_graphics {
	sf::RenderWindow* window;
	int window_height;
	int window_width;
	sprite_params** field;
	int field_height;
	int field_width;
	sf::Texture water;
	sf::Texture ice;
	sf::Texture swamp;
	sf::Texture rainforest;
	sf::Texture desert;
	sf::Texture savanna;
	sf::Texture grassland;
	sf::Texture snow;
	sf::Texture error_texture;
public:
	map_graphics(sf::RenderWindow* window, int window_height, int window_width, sprite_params** field, int field_height, int field_width);
	void load_textures();
	void heat_map();
	void biome_map();
	void water_map();

};