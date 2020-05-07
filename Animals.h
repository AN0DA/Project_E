#pragma once
#include "Animal_stats.h"


class Animal
{
public:
	Animal();
	Animal(int _x, int _y, bool _sex, unsigned short _repro = 20, unsigned short _size = 10, unsigned short _sight = 10, Animal _parents[2] = {});
	Animal(int _x, int _y, bool _sex, unsigned short _repro , unsigned short _size , unsigned short _sight , Animal _parents[2], Stat* _health = NULL, Stat* _age = NULL, Stat* _thirst = NULL, Stat* _hunger = NULL);

	//setter
	void set_x(int _x);
	void set_y(int _y);
	void set_sex(bool _sex);
	void set_reproduction(unsigned short _repro);
	void set_sight(unsigned short _sight);
	void set_parents(Animal _parent1, Animal _parent2 );
	void set_sprite(std::string _sprite_path);

	bool is_dead();

	//getter
	unsigned short get_x();
	unsigned short get_y();
	bool get_sex();
	unsigned short get_reproduction();
	unsigned short get_sight();
	std::vector<Animal> get_parents(unsigned int _precision = 4);
	std::string get_sprite();

	//unsigned int get_animal_count();

	Stat health;
	Stat age;
	Stat thirst;
	Stat hunger;

private:
	//const unsigned int id;
	int position_x;
	int position_y;
	bool sex; //false = female, true = male;

	unsigned short size;
	unsigned short reproduction_age;
	unsigned short sight;
	std::vector<Animal> parents;

	std::string sprite_path;


	//static unsigned int animals_count;
};

class Cat : public Animal
{
public:
	Cat();
	~Cat();

private:

};

