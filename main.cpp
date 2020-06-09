#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include <iostream>
#include <vector>
#include <string>

#include "Core.h"
#include "Animal_core.h"
#include "env_gen.h"
#include "map_graphics.h"

enum class current_map {
	biome,
	heat,
	water
};

current_map m;



int main()
{
	/*Animals_gen table;
	Animal kot(50, 50, false);
	kot.set_sprite("textures/Cat.png");
	table.create_new(kot);*/
	int window_width = 1000;
	int window_height = 1000;

	env_gen environment_generator;
	TreeDaemon mtd;
	//Core core;
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Project E");
	//Core core;
	//core.StartProjectE(core, &window);
	 //texture init for landscape

	sprite_params** field;
	int field_height;
	int field_width;
	//end of lodin
	field_height = 100;
	field_width = 100;
	// generating table of fields and sprite is inside
	field = new sprite_params * [field_width];
	for (int i = 0; i < field_width; i++) {
		field[i] = new sprite_params[field_height];
	}
		
	env_gen environment_generator;
	environment_generator.generate_environment(field, field_width-1, field_height-1);
	std::cout << "generated";
	map_graphics g(&window, window_height, window_width, field,  field_height, field_width);
	g.biome_map();
	//biome_map(&window, field, width, height);
	window.display();

	//window.setFramerateLimit(1);
	while (window.isOpen())
	{

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
					window.clear(sf::Color::Black);
					std::cout << "SPACJA";
					switch (m)
					{
					case current_map::biome:
						g.heat_map();
						m = current_map::heat;
						break;
					case current_map::heat:
						g.water_map();
						m = current_map::water;
						break;
					case current_map::water:
						g.biome_map();
						m = current_map::biome;
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
					field[i][j].sprite.setPosition(sf::Vector2f(i * 32, j * 32));
					//window->setVisible();
					window.draw(field[i][j].sprite);
				}
			}
			environment_generator.setData(e.get_data());
			sprite_params* toPole = &(environment_generator.get_data()[7][6]);
			mtd.addTree(Tree(toPole, 2, 1, 3, 224, 192));
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
			needtogenerate = false;
			//window.display();
		}
		environment_generator.tick(environment_generator.get_data(), environment_generator.get_width(), environment_generator.get_height(), &mtd, &window);
	}
};