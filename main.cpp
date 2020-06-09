#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <string>
#include <time.h>
#include <stdlib.h>
#include <Windows.h>
#include <cstdlib>


#include "Core.h"
#include "Animal_core.h"
#include "env_gen.h"

bool needtogenerate = true;
const int x = 30;

int main()
{	
	//Defining random
	srand(time(NULL));
	
	//Core core;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Project E");
	//Core core;
	//core.StartProjectE(core, &window);
	 //texture init for landscape

	//Preparing Animals Objects
	std::vector<Animals_gen> Animals;

	
	while (window.isOpen())
	{
		window.clear();
		if (true)
		//if(needtogenerate)
		{
			//Preparing Animals Objects
			Animals = prepare_animals();

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
			


			// generating table of fields and sprite is inside
			/*sprite_params** field = new sprite_params* [x];
			for (int i = 0; i < x; i++) {
				field[i] = new sprite_params[x];
			} */
			//Preparing World table
			sprite_params** field = new sprite_params * [x];
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
			//for (int i = 0; i< x; i++)
			//	sprite_data[i] = new sprite_params[y];

			//env_gen habitat;
			//habitat.generate_environment(sprite_data, x, y);

			//needtogenerate = false;
		}


		
		//Animal Modifying 

		for (int i = 0; i < Animals.size(); i++)
		{
			for (int j = 0; j < Animals[i].get_amount(); j++)
			{
				Animal temp_animal = Animals[i].get_animal(j);
				if (temp_animal.get_x() > 0 && temp_animal.get_x() < x)
					temp_animal.set_x(temp_animal.get_x() + (std::rand() % 3) - 1);
				if (temp_animal.get_y() > 0 && temp_animal.get_y() < x) 
					temp_animal.set_y(temp_animal.get_y() + (std::rand() % 3) - 1);
				if (temp_animal.get_y() <= 0 )
					temp_animal.set_y(0 + std::rand() % 2);
				if (temp_animal.get_x() <= 0)
					temp_animal.set_x(0 + std::rand() % 2);
				if (temp_animal.get_x() >= x)
					temp_animal.set_x(x - std::rand() % 2);
				if (temp_animal.get_y() >= x)
					temp_animal.set_y(x - std::rand() % 2);
				


				
				Animals[i].update_animal(j, temp_animal);
				std::cout << Animals[i].get_animal(j).get_x() << "\n";
			}


		}

		//Animal Rendering
		for (int i = 0; i < Animals.size(); i++)
		{
			std::vector<sf::Sprite> animal_sprites;
			animal_sprites = Animals[i].generate_animals();
			for (int j = 0; j < animal_sprites.size(); j++)
			{
				//animal_sprites[j].setPosition(sf::Vector2f(animal_sprites[j].getPosition().x + 32 * rand() % 3, animal_sprites[j].getPosition().y + 32 * rand() % 3));
				window.draw(animal_sprites[j]);
			}

		}
		Sleep(10);
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