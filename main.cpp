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
	srand(time(NULL));
	/*Animals_gen table;
	Animal kot(50, 50, false);
	kot.set_sprite("textures/Cat.png");
	table.create_new(kot);*/
	int window_width = 1000;
	int window_height = 1000;

	env_gen environment_generator;
	TreeDaemon mtd;
	//Core core;
	sf::RenderWindow window(sf::VideoMode(window_width, window_height), "Project_E");
	//Core core;
	//core.StartProjectE(core, &window);
	 //texture init for landscape

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
	double scale_width = window_width /(double)(32 * field_width);
	double scale_height =  window_height /(double)(32 * field_height);

	std::cout << scale_width;
	environment_generator.generate_environment(field, field_width-1, field_height-1);
	std::cout << "generated";
	map_graphics g(&window, scale_height, scale_width, field,  field_height, field_width);
	g.biome_map();
	//biome_map(&window, field, width, height);
	environment_generator.setData(environment_generator.get_data());
	sprite_params* toPole = &(environment_generator.get_data()[7][6]);
	mtd.addTree(Tree(toPole, 2, 1, 3, 7*32*scale_width, 6*32*scale_height));
	window.display();
	//window.setFramerateLimit(1);
	while (window.isOpen())
	{

				else if (evt.key.code == sf::Keyboard::P) {
					bool pause = true;
					while (pause) {
						sf::Event e;
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
			environment_generator.tick(environment_generator.get_data(), environment_generator.get_width(), environment_generator.get_height(), &mtd, &window,&g,scale_width,scale_height);
		}
	}
};