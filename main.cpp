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

	env_gen e;
	e.generate_environment(field, field_width-1, field_height-1);
	std::cout << "generated";
	map_graphics g(&window, window_height, window_width, field,  field_height, field_width);
	g.biome_map();
	//biome_map(&window, field, width, height);


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
					}
				}
				break;

			}
			//window.display(); <----- EPILEPSJA

			needtogenerate = false;
			window.display();
		}
		environment_generator.tick(environment_generator.get_data(), environment_generator.get_width(), environment_generator.get_height());
	}
};