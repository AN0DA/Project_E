#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <string>

#include "Core.h"
#include "Animal_core.h"
#include "env_gen.h"

bool needtogenerate = true;

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
	while (window.isOpen())
	{
		if (needtogenerate)
		{
			sf::Texture water;
			if (!water.loadFromFile("textures/water.jpg"))
			{
				std::cout << "Water isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded Water" << std::endl; }


			sf::Texture ice;
			if (!ice.loadFromFile("textures/ice.jpg"))
			{
				std::cout << "Ice isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded ice" << std::endl; }


			sf::Texture rainforest;
			if (!rainforest.loadFromFile("textures/rainforest.jpg"))
			{
				std::cout << "Rainforest isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded rainforest" << std::endl; }


			sf::Texture desert;
			if (!desert.loadFromFile("textures/desert.jpg"))
			{
				std::cout << "Desert isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded desert" << std::endl; }


			sf::Texture savanna;
			if (!savanna.loadFromFile("textures/savanna.jpg"))
			{
				std::cout << "Savanna isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded savanna" << std::endl; }


			sf::Texture grassland;
			if (!grassland.loadFromFile("textures/grassland.jpg"))
			{
				std::cout << "Grassland isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded grassland" << std::endl; }


			sf::Texture snow;
			if (!snow.loadFromFile("textures/snow.jpg"))
			{
				std::cout << "Snow isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded snow" << std::endl; }


			sf::Texture error_texture;
			if (!snow.loadFromFile("textures/error_texture.jpg"))
			{
				std::cout << "Error isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded error_texture" << std::endl; }


			//end of lodin
			const int x = 100;
			// generating table of fields and sprite is inside
			sprite_params** field = new sprite_params* [x];
			for (int i = 0; i < x; i++) {
				field[i] = new sprite_params[x];
			}
			env_gen e;
			e.generate_environment(field, x-1, x-1);
			std::cout << "generated";
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < x; j++)
				{
					
					Biomes b = field[i][j].getBiome();
					switch (b)
					{
					case Biomes::water:
						field[i][j].sprite.setTexture(water);
						break;
					case Biomes::ice:
						field[i][j].sprite.setTexture(ice);
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
					field[i][j].sprite.setPosition(sf::Vector2f(j * 10, i * 10));
					//window->setVisible();
					window.draw(field[i][j].sprite);
				}
			}
			window.display();
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
			}
			//window.display(); <----- EPILEPSJA
		}
	}
};