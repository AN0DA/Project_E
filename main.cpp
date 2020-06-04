#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>


#include "Core.h"
#include "Animal_core.h"
#include "env_gen.h"

bool needtogenerate = true;

int main()
{	
	//Defining random
	srand(time(NULL));
	
	//Core core;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Project E");
	//Core core;
	//core.StartProjectE(core, &window);
	 //texture init for landscape


	//Animal Texture
	sf::Texture cat_texture;
	if (!cat_texture.loadFromFile("textures/Cat.png"))
		std::cout << "Error isnt loaded!" << std::endl;
	else  std::cout << "properly loaded cat" << std::endl; 

	sf::Texture camel_texture;
	if (!camel_texture.loadFromFile("textures/Camel.png"))
		std::cout << "Error isnt loaded!" << std::endl;
	else std::cout << "properly loaded camel" << std::endl; 

	//generating animals
	Animals_gen Cats(cat_texture);
	Animals_gen Camels(camel_texture);
	for (int i = 0; i < 4; i++)
	{
		Cat temp_anim(rand() % 30, rand() % 30, rand() % 2); //Creating cat with semiradnom parameters and putting in Cats array
		Cats.set_new(temp_anim);

	}
	for (int i = 0; i < 4; i++)
	{
		Camel temp_anim(rand() % 30, rand() % 30, rand() % 2); //Creating camel with semirandom parameters and putting in Camels array
		Camels.set_new(temp_anim);
	}
	

	while (window.isOpen())
	{
		if (needtogenerate)
		{
			//Ground Textures
			sf::Texture water;
			if (!water.loadFromFile("textures/water.jpg"))
			{
				std::cout << "Water isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt0" << std::endl; }


			sf::Texture ice;
			if (!ice.loadFromFile("textures/ice.jpg"))
			{
				std::cout << "Ice isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt1" << std::endl; }


			sf::Texture rainforest;
			if (!rainforest.loadFromFile("textures/rainforest.jpg"))
			{
				std::cout << "Rainforest isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt2" << std::endl; }


			sf::Texture desert;
			if (!desert.loadFromFile("textures/desert.jpg"))
			{
				std::cout << "Desert isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt3" << std::endl; }


			sf::Texture savanna;
			if (!savanna.loadFromFile("textures/savanna.jpg"))
			{
				std::cout << "Savanna isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt4" << std::endl; }


			sf::Texture grassland;
			if (!grassland.loadFromFile("textures/grassland.jpg"))
			{
				std::cout << "Grassland isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt5" << std::endl; }


			sf::Texture snow;
			if (!snow.loadFromFile("textures/snow.jpg"))
			{
				std::cout << "Snow isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt6" << std::endl; }


			sf::Texture error_texture;
			if (!snow.loadFromFile("textures/error_texture.jpg"))
			{
				std::cout << "Error isnt loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt7" << std::endl; }


			//end of loadin
			const int x = 30;


			// generating table of fields and sprite is inside
			sprite_params** field = new sprite_params* [x];
			for (int i = 0; i < x; i++) {
				field[i] = new sprite_params[x];
			}
			env_gen e;
			e.generate_environment(field, x-1, x-1);
			needtogenerate = false;
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
					
					//sprites[i][j].setColor(sf::Color(core.GenerateRandomInt(10), core.GenerateRandomInt(10), core.GenerateRandomInt(10)));
					//just to get clear sprites are assigned to fields
					/*
					if (j >= y && i <= y)
					{
						field[i][j].sprite.setTexture(grassland);
					}
					else if (j >= y && i > y)
					{
						field[i][j].sprite.setTexture(savanna);
					}
					else  if (j < y && i >= y)
					{
						field[i][j].sprite.setTexture(snow);
					}
					else
					{
						field[i][j].sprite.setTexture(desert);
					}
					*/
					

					field[i][j].sprite.setPosition(sf::Vector2f(i * 32, j * 32));
					//window->setVisible();
					window.draw(field[i][j].sprite);
				}
			}

			//Animal Rendering
			std::vector<sf::Sprite> animal_sprites;
			animal_sprites = Cats.generate_animals();
			std::vector<sf::Sprite> temp_camel = Camels.generate_animals();
			animal_sprites.insert(std::end(animal_sprites), std::begin(temp_camel), std::end(temp_camel));
			for (int i = 0; i < animal_sprites.size(); i++)
			{	
				window.draw(animal_sprites[i]);
			}

			
			/*
			//render  other biomes!
			const int NoB = 4;
			for (int k = 1; NoB > k; k++)
			{
				int i = int(x+8 / k + 12);
				int j = int(x+8 / k - 8);
				//sprites[i][j].setTexture(sand);
				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < core.GenerateRandomInt(10); n++)
					{
						sprites[i +n][j+m].setTexture(sand);
					}
				}
			}
			for (int k = 1; NoB > k; k++)
			{
				int i = int(x / k * 3 + 7);
				int j = int(x / k * 3 + 8);
				//sprites[i][j].setTexture(sawannah);
			sf::Texture sand;
			if (!sand.loadFromFile("textures/sand2.jpg"))
			{
				std::cout << "Sand isn't loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt1" << std::endl; }
			sf::Texture sawannah;
			if (!sawannah.loadFromFile("textures/sawannah.jpg"))
			{
				std::cout << "Sand isn't loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt2" << std::endl; }
			sf::Texture snow;
			if (!snow.loadFromFile("textures/snow.jpg"))
			{
				std::cout << "snow isn't loaded!" << std::endl;
			}
			else { std::cout << "properly loaded txt3" << std::endl; }
			sf::Texture grass;
			if (!grass.loadFromFile("textures/grass.jpg"))
			{
				std::cout << "Grass isn't loaded! << std::endl << std::endl";
			}
			else { std::cout << "properly loaded txt4" << std::endl << std::endl; }
			//end of loading

			const int x = 50;
			const int y = 20;
			sf::Sprite sprites[x][x];
			for (int i = 0; i < x; i++)
			{
				for (int j = 0; j < x; j++)
				{
					//sprites[i][j].setColor(sf::Color(core.GenerateRandomInt(10), core.GenerateRandomInt(10), core.GenerateRandomInt(10)));

					if (j >= y && i <= y)
					{
						sprites[i][j].setTexture(grass);
					}
					else if (j >= y && i > y)
					{
						sprites[i][j].setTexture(sawannah);
					}
					else  if (j < y && i >= y)
					{
						sprites[i][j].setTexture(snow);
					}
					else
					{
						sprites[i][j].setTexture(sand);
					}

					sprites[i][j].setPosition(sf::Vector2f(i * 32, j * 32));
					//window->setVisible();
					window.draw(sprites[i][j]);
				}
			}
			/*
			//render  other biomes!
			const int NoB = 4;
			for (int k = 1; NoB > k; k++)
			{
				int i = int(x+8 / k + 12);
				int j = int(x+8 / k - 8);
				//sprites[i][j].setTexture(sand);
				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < core.GenerateRandomInt(10); n++)
					{
						sprites[i +n][j+m].setTexture(sand);
					}
				}
			}
			for (int k = 1; NoB > k; k++)
			{
				int i = int(x / k * 3 + 7);
				int j = int(x / k * 3 + 8);
				//sprites[i][j].setTexture(sawannah);
				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < 10; n++)
					{
						sprites[i + n][j + m].setTexture(sawannah);
					}
				}
			}
			for (int k = 1; NoB > k; k++)
			{
				int i = int(x / k * 2 + 2);
				int j = int(x / k * 2 - 3);
				//sprites[i][j].setTexture(snow);

				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < 10; n++)
					{
						sprites[i + n][j + m].setTexture(sawannah);
					}
				}
			}
			for (int k = 1; NoB > k; k++)
			{
				int i = int(x / k * 2 + 2);
				int j = int(x / k * 2 - 3);
				//sprites[i][j].setTexture(snow);
				for (int m = 0; m < 10; m++)
				{
					for (int n = 0; n < 10; n++)
					{
						sprites[i + n][j + m].setTexture(snow);
					}
				}
						sprites[i + n][j + m].setTexture(snow);
					}
				}
			}
			*/
			//window.display(); //<----- EPILEPSJA

			//Generate natural environment
			//sprite_params** sprite_data = new sprite_params * [x];
			//for (int i = 0; i < x; i++)
			//	sprite_data[i] = new sprite_params[y];

			//env_gen habitat;
			//habitat.generate_environment(sprite_data, x, y);

			//needtogenerate = false;
		}

		window.display();
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
			needtogenerate = false;
			window.display();
		}
	}
};