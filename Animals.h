#pragma once
#include "Animal_stats.h"

///Implementation of an instance of an Animal
class Animal
{
public:

	/**
	* Creating constructor of an Animal
	* None of fields is mandatory
	*
	* @param _x, _y location of an animal
	* @param _sex Gender of an animal
	* @param _repro Age at which an animal can reproduce
	* @param _size Size of an animal
	* @param _sight Distance at which an animal can see
	* @param _parents Array of two other animals which are parents of the new one
	* @param _health object Health
	* @param _age object Age
	* @param _thirst object Thirst
	* @param _hunger object Hunger
	*/
	Animal(int _x = 0, int _y = 0, bool _sex = 0, unsigned short _repro = 20, unsigned short _size = 10, unsigned short _sight = 10, Animal *_parents = NULL, Stat* _health = NULL, Stat* _age = NULL, Stat* _thirst = NULL, Stat* _hunger = NULL);

	/**
	* Sets X coordinate of an animal
	*
	* @param _x X position
	*/
	void set_x(int _x);
	/**
	* Sets Y coordinate of an animal
	*
	* @param _y Y position
	*/
	void set_y(int _y);
	/**
	* Sets gender of an animal
	*
	* @param _sex Gender: False - Female, True - Male
	*/
	void set_sex(bool _sex);
	/**
	* Sets reproduction age of an animal
	*
	* @param _reproduction Age at which animal can have children
	*/
	void set_reproduction(unsigned short _repro);
	/**
	* Sets distance animal can see
	*
	* @param _sight Distance
	*/
	void set_sight(unsigned short _sight);
	/**
	* Sets both parents of an animal
	* Second not mandatory
	* @param _parent1 First parent
	* @param _parent2 Second parent
	*/
	void set_parents(Animal _parent1, Animal _parent2 = NULL);
	/**
	* Sets file path to texture of animal
	*
	* @param _sptite_path String with file path to textur file
	*/
	void set_sprite(std::string _sprite_path);
	/**
	* Checks whether an animal is dead or not
	*/
	bool is_dead();

	/**
	* @return X position of animal
	*/
	unsigned short get_x();
	/**
	* @return Y position of animal
	*/
	unsigned short get_y();
	/**
	* @return gender of animal
	*/
	bool get_sex();
	/**
	* @return reproduction age of animal
	*/
	unsigned short get_reproduction();
	/**
	* @return how far an animal can see
	*/
	unsigned short get_sight();
	/**
	* @param _precision how many levels of genealogical tree to search for
	*
	* @return list ancestors with given precision
	*/
	std::vector<Animal> get_parents(unsigned int _precision = 4);
	/**
	* @return string with path to texture file of animal
	*/
	std::string get_sprite();

	//unsigned int get_animal_count();

	///Object that describes Health of an animal
	Stat health;
	///Object that describes Age of an animal
	Stat age;
	///Object that describes Thirst of an animal
	Stat thirst;
	///Object that describes Hunger of an animal
	Stat hunger;

private:

	/// X Position of an Animal
	int position_x;
	/// Y Position of an Animal
	int position_y;
	/** Gender of an animal
	* False == Female,
	* True == Male
	*/
	bool sex;
	/// Size of an animal
	unsigned short size;
	/// Age at which animal can create children
	unsigned short reproduction_age;
	/// Distance at which an animal can see objects
	unsigned short sight;
	/// Array of two objects, parents of an animal
	std::vector<Animal> parents;
	/// File path to animal texture
	std::string sprite_path;
};

class Cat : public Animal
{
public:

private:
};
