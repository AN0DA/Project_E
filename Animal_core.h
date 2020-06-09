#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <string>

#include "Animals.h"
#include "Animal_actions.h"
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
	Animals_gen(sf::Texture _texture);

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
	Updates existing animal

	@param _index Number of animal

	@param _Animal Animal that overrites
	*/
	void update_animal(int _index, Animal _Animal);
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
	/**
		Return texture
	*/
	sf::Texture get_texture();

private:
	/**
	* Vector with all animals
	*
	* @return Vector of animals
	*/
	sf::Texture texture;
	std::vector<Animal> Animals_all;
	
};

/**
function that prepares animal objects
and return array of them

*/
std::vector<Animals_gen>  prepare_animals();