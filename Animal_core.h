#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Animals.h"

/**
* Class that generates and contains all animals
*/
class Animals_gen
{
public:
	///Constructot
	Animals_gen();
	///Destructor
	~Animals_gen();

	/**
	* Generate animals in window
	*
	* @param window variable
	*/
	void generate_animals(sf::Window* window);
	/**
	* Create new animal
	*
	* @param _animal Animal object to add to list of animals
	*/
	void create_new(Animal _animal);

private:
	/**
	* Vector with all animals
	*
	* @return Vector of animals
	*/
	std::vector<Animal> Animals_all;
};