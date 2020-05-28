#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <string>

#include "Core.h"
#include "Animal_core.h"
#include "env_gen.h"


enum class map {
	biome,
	heat,
	water
};

map m;

bool needtogenerate = true;

bool need_to_load_biomes_from_file = true;



void heat_map(sf::RenderWindow* window, sprite_params** field, int width, int height) {

	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
			int temp = field[i][j].get_temperature();
			sf::RectangleShape rect;
			rect.setSize(sf::Vector2f(10, 10));
			if (temp >= 20) { //<20,35>
				rect.setFillColor(sf::Color(255, (255-(temp-20)*17), 0, 255));
			}
			else if (temp >= 4) { //<4,19>
				rect.setFillColor(sf::Color((255-(temp-4)*17), 255, 0, 255));
			}
			else { // <-10,3>
				rect.setFillColor(sf::Color(0, 255, (255-(temp+10)*15), 255));
			}
			rect.setPosition(sf::Vector2f(i * 10, j * 10));
			(*window).draw(rect);
		}
	}
	(*window).display();
}

void biome_map(sf::RenderWindow* window, sprite_params ** field, int width, int height) {

	sf::Texture water;
	sf::Texture ice;
	sf::Texture swamp;
	sf::Texture rainforest;
	sf::Texture desert;
	sf::Texture savanna;
	sf::Texture grassland;
	sf::Texture snow;
	sf::Texture error_texture;
	//if (need_to_load_biomes_from_file) {
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
		need_to_load_biomes_from_file = false;
	//}


	for (int j = 0; j < height; j++) {
		for (int i = 0; i < width; i++) {
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
			field[i][j].sprite.setPosition(sf::Vector2f(i * 10, j * 10));
			(*window).draw(field[i][j].sprite);
		}
	}
	(*window).display();
}

int main()
{
	/*Animals_gen table;
	Animal kot(50, 50, false);
	kot.set_sprite("textures/Cat.png");
	table.create_new(kot);*/

	//Core core;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Project E");
	//Core core;
	//core.StartProjectE(core, &window);
	 //texture init for landscape

	sprite_params** field;
	int width;
	int height;
	//end of lodin
	width = 100;
	height = 100;
	// generating table of fields and sprite is inside
	field = new sprite_params * [width];
	for (int i = 0; i < width; i++) {
		field[i] = new sprite_params[height];
	}
	while (window.isOpen())
	{
	


		if (needtogenerate) {
			env_gen e;
			e.generate_environment(field, width-1, height-1);
			std::cout << "generated";
			biome_map(&window, field, width, height);
			needtogenerate = false;
		}
		//window.display();
		sf::Event evt;
		while (window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				window.close();
				break;
			case sf::Event::KeyPressed:
				if (evt.key.code == sf::Keyboard::Space) {
					std::cout << "SPACJA";
					switch (m)
					{
					case map::biome:
						heat_map(&window, field, width, height);
						m = map::heat;
						break;
					case map::heat:
						//TODO WATER MAP
						m = map::water;
						break;
					case map::water:
						biome_map(&window, field, width, height);
						m = map::biome;
						break;
					}
				}
				break;
			}
			//window.display(); <----- EPILEPSJA
		}
	}
};