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
	///Constructor
	Animals_gen() = default;
	/**
	Constructor with defining texture for animal group

	@param _texture Texture path for animals group
	*/
	Animals_gen(std::string _texture);

	///Destructor
	~Animals_gen();

	/**
	* Generate animals in window
	*
	* @param window variable
	*/
	std::vector< sf::Sprite > generate_animals();
	/**
	* Create new animal
	*
	* @param _animal Animal object to add to list of animals
	*/
	void set_new(Animal _animal);
	/**
	* Get Animal on given index
	*
	* @param _index Index of animal to return
	*/
	Animal get_animal(int _index);
	/**
	* Removes Animal
	*
	* @param _index Index of animal to remove
	*/
	void remove_animal(int _index);

	/**
	* Get Amount of animals
	*
	* @return Amount of animals
	*/
	int get_amount();

private:
	/**
	* Vector with all animals
	*
	* @return Vector of animals
	*/
	std::vector<Animal> Animals_all;
	sf::Texture texture;
};