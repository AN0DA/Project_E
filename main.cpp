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
	water,
	pressure
};

current_map m;

int main()
{
	srand(time(NULL));
	/*Animals_gen table;
	Animal kot(50, 50, false);
	kot.set_sprite("textures/Cat.png");
	table.create_new(kot);*/
	int window_width = 1000;
	int window_height = 1000;

	env_gen environment_generator;
	TreeDaemon mtd;

	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Project_E");

	sprite_params** field;
	int field_height;
	int field_width;
	//end of loading
	field_height = 100;
	field_width = 100;
	// generating table of fields and sprite is inside
	field = new sprite_params * [field_width];
	for (int i = 0; i < field_width; i++) {
		field[i] = new sprite_params[field_height];
	}
	double scale_width = window_width / (double)(32 * field_width);
	double scale_height = window_height / (double)(32 * field_height);

	std::cout << "scaling factor for textures: " << scale_width << std::endl;
	environment_generator.generate_environment(field, field_width - 1, field_height - 1);
	std::cout << "generated";
	map_graphics g(&window, scale_height, scale_width, field, field_height, field_width);
	g.biome_map();
	std::cout << "map";
	environment_generator.setData(environment_generator.get_data());
	sprite_params* toPole = &(environment_generator.get_data()[7][6]);
	mtd.addTree(Tree(toPole, 2, 1, 3, 7 * 32 * scale_width, 6 * 32 * scale_height));
	window.display();
	window.setFramerateLimit(30);
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
					window.clear();
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
						g.pressure_map();
						m = current_map::pressure;
						break;
					case current_map::pressure:
						g.biome_map();
						m = current_map::biome;
					}
					window.display();
				}
				else if (evt.key.code == sf::Keyboard::P) {
					bool pause = true;
					while (pause) {
						sf::Event e;
						while (window.pollEvent(e)) {
							if (e.type == sf::Event::KeyPressed) {
								if (e.key.code == sf::Keyboard::P) {
									std::cout << "A";
									pause = false;
								}
							}
						}
					}
				}
			}
		}
		if (m == current_map::biome) {
			//environment_generator.tick(environment_generator.get_data(), environment_generator.get_width(), environment_generator.get_height(), &mtd, &window, &g, scale_width, scale_height);
		}
	}
};