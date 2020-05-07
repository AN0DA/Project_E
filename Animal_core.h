#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Animals.h"


class Animals_gen
{
public:
	Animals_gen();
	~Animals_gen();

	void generate_animals(sf::Window* window);
	void create_new(Animal _animal);

private:
	std::vector<Animal> Animals_all;


};