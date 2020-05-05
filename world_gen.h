#pragma once
#include <SFML/Graphics.hpp>

class world_gen
{
	int seed = 3092182;
public:
	void generate_world(sf::Window* window);
};
