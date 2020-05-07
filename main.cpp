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
	Animals_gen table;
	Animal kot(50, 50, false);
	kot.set_sprite("textures/Cat.png");
	table.create_new(kot);



	Core core;
	sf::RenderWindow window(sf::VideoMode(1000, 1000), "Project E");
	//Core core;
	//core.StartProjectE(core, &window);
	 //texture init for landscape
	while (window.isOpen())
	{
		if (needtogenerate)
		{
			sf::Texture sand;
			if (!sand.loadFromFile("textures/sand2.jpg"))
			{
				std::cout << "Sand isnt loaded!";
			}
			else { std::cout << "properly loaded txt1"; }
			sf::Texture sawannah;
			if (!sawannah.loadFromFile("textures/sawannah.jpg"))
			{
				std::cout << "Sand isnt loaded!";
			}
			else { std::cout << "properly loaded txt2"; }
			sf::Texture snow;
			if (!snow.loadFromFile("textures/snow.jpg"))
			{
				std::cout << "snow isnt loaded!";
			}
			else { std::cout << "properly loaded txt3"; }
			sf::Texture grass;
			if (!grass.loadFromFile("textures/grass.jpg"))
			{
				std::cout << "Grass isnt loaded!";
			}
			else { std::cout << "properly loaded txt4"; }
			//end of lodin
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
			sprite_params** sprite_data = new sprite_params* [x];
			for (int i = 0; i < x; i++)
				sprite_data[x] = new sprite_params[y];

			env_gen habitat;
			std::cout;
			habitat.generate_environment(sprite_data, x, y);

			needtogenerate = false;
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
			*/
			//window.display(); <----- EPILEPSJA
			needtogenerate = false;
			window.display();

		}

	sf::Event evt;
	while (window.pollEvent(evt))
	{
		switch(evt.type)
			{ 
			case sf::Event::Closed:
					window.close();
					break;
			}
		}

	}
}