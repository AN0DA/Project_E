/// \file
/// \brief Source file for map_graphics
/// \details Source file for env_temperature environment parameter. Currently only generates temperature, in future will also mix it as time passes.
/// \author Konstanty Kordas
/// \date 9.06.2020
/// \version 0.10
#include "map_graphics.h"
#include <iostream>

/// \brief map_graphics class constructor
/// \author Konstanty Kordas
/// consrtuctor initializes all local variables needed and calls load_textures() function to load aditional textures from files
map_graphics::map_graphics(sf::RenderWindow* window, int window_height, int window_width, sprite_params** field, int field_height, int field_width) {
	this->window = window;
	this->window_height = window_height;
	this->window_width = window_width;
	this->field = field;
	this->field_height = field_height;
	this->field_width = field_width;
	load_textures();
}

/// fuction that loads textures from files and logs in console success and failure
void map_graphics::load_textures() {
	if (!water.loadFromFile("textures/water.jpg")) {
		std::cout << "Water isnt loaded!" << std::endl;
	}
	else {
		std::cout << "properly loaded Water" << std::endl;
	}

	if (!ice.loadFromFile("textures/ice.jpg")) {
		std::cout << "Ice isnt loaded!" << std::endl;
	}
	else {
		std::cout << "properly loaded ice" << std::endl;
	}

	if (!swamp.loadFromFile("textures/swamp.jpg")) {
		std::cout << "Swamp isnt loaded!" << std::endl;
	}
	else {
		std::cout << "properly loaded swamp" << std::endl;
	}

	if (!rainforest.loadFromFile("textures/rainforest.jpg")) {
		std::cout << "Rainforest isnt loaded!" << std::endl;
	}
	else {
		std::cout << "properly loaded rainforest" << std::endl;
	}

	if (!desert.loadFromFile("textures/desert.jpg")) {
		std::cout << "Desert isnt loaded!" << std::endl;
	}
	else {
		std::cout << "properly loaded desert" << std::endl;
	}

	if (!savanna.loadFromFile("textures/savanna.jpg")) {
		std::cout << "Savanna isnt loaded!" << std::endl;
	}
	else {
		std::cout << "properly loaded savanna" << std::endl;
	}

	if (!grassland.loadFromFile("textures/grassland.jpg")) {
		std::cout << "Grassland isnt loaded!" << std::endl;
	}
	else {
		std::cout << "properly loaded grassland" << std::endl;
	}

	if (!snow.loadFromFile("textures/snow.jpg")) {
		std::cout << "Snow isnt loaded!" << std::endl;
	}
	else {
		std::cout << "properly loaded snow" << std::endl;
	}

	if (!error_texture.loadFromFile("textures/error_texture.jpg")) {
		std::cout << "Error isnt loaded!" << std::endl;
	}
	else {
		std::cout << "properly loaded error_texture" << std::endl;
	}
}

/// \brief function draws graphics based on biomes
/// \author Konstanty Kordas
/// function iterates through entire grid and for every block it checks the biome, sets it corresponding texture and draws it on the window
void map_graphics::biome_map() {
	for (int j = 0; j < field_height; j++) {
		for (int i = 0; i < field_width; i++) {
			Biomes b = field[i][j].getBiome();
			switch (b)
			{
			case Biomes::water:
				field[i][j].sprite.setTexture(water);
				break;
			case Biomes::ice:
				field[i][j].sprite.setTexture(ice);
				break;
			case Biomes::swamp:
				field[i][j].sprite.setTexture(swamp);
				break;
			case Biomes::rainforest:
				field[i][j].sprite.setTexture(rainforest);
				break;
			case Biomes::desert:
				field[i][j].sprite.setTexture(desert);
				break;
			case Biomes::savanna:
				field[i][j].sprite.setTexture(savanna);
				break;
			case Biomes::grassland:
				field[i][j].sprite.setTexture(grassland);
				break;
			case Biomes::snow:
				field[i][j].sprite.setTexture(snow);
				break;
			default:
				field[i][j].sprite.setTexture(error_texture);
				break;
			}
			field[i][j].sprite.setPosition(sf::Vector2f(i * window_width / field_width, j * window_height / field_height));
			(*window).draw(field[i][j].sprite);
		}
	}
}



/// \brief function draws graphics based on temperature
/// \author Konstanty Kordas
/// function iterates through entire grid and for every block it checks the temperature and draws corresponding rectangle with correct color
void map_graphics::heat_map() {
	for (int j = 0; j < field_height; j++) {
		for (int i = 0; i < field_width; i++) {
			sf::RectangleShape rect;
			rect.setSize(sf::Vector2f(10, 10));
			double temp = field[i][j].get_temperature();
			if (temp >= 20) { //<20,35>
				rect.setFillColor(sf::Color(255, (255 - (temp - 20) * 17), 0, 255));
			}
			else if (temp >= 4) { //<4,19>
				rect.setFillColor(sf::Color((255 - (temp - 4) * 17), 255, 0, 255));
			}
			else { // <-10,3>
				rect.setFillColor(sf::Color(0, 255, (255 - (temp + 10) * 15), 255));
			}
			rect.setPosition(sf::Vector2f(i * window_width/field_width, j * window_height/field_height));
			(*window).draw(rect);
		}
	}

}

/// \brief function draws graphics based on temperature
/// \author Konstanty Kordas
/// function iterates through entire grid and for every block it checks the humidity and draws corresponding rectangle with correct color
void map_graphics::water_map() {
	for (int j = 0; j < field_height; j++) {
		for (int i = 0; i < field_width; i++) {
			sf::RectangleShape rect;
			rect.setSize(sf::Vector2f(window_width / field_width, window_height / field_height));
			if (field[i][j].isWater()) {
				rect.setFillColor(sf::Color(100, 100, 100));
			}
			else {
				double humidity = field[i][j].getHumidity();
				if (humidity > 66) {
					rect.setFillColor(sf::Color(0, (33 - (humidity - 67)) * 7, 255, 255));
				}
				else if (humidity > 33) {
					rect.setFillColor(sf::Color(0, 231, 31 + (humidity - 34) * 7, 255));
				}
				else {
					rect.setFillColor(sf::Color((33 - humidity) * 7, 231, 231, 255));
				}
			}
			rect.setPosition(sf::Vector2f(i * window_width / field_width, j * window_height / field_height));
			(*window).draw(rect);
		}
	}

}