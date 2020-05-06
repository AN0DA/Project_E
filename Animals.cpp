#pragma once
#include <vector>
#include <string>
#include "Animals.h"



Animal::Animal()
{
	position_x = 0;
	position_y = 0;
	sex = false; //false = female, true = male;
	size = 10;
	reproduction_age = 20;
	sight = 10;
	parents = {};
}
Animal::Animal(int _x, int _y, bool _sex, unsigned short _repro, unsigned short _size, unsigned short _sight, Animal _parents[2]) {
	position_x = _x;
	position_y = _y;
	sex = _sex; //false = female, true = male;
	size = _size;
	reproduction_age = _repro;
	sight = _sight;
	parents = {_parents[0], _parents[1]};
}
Animal::Animal(int _x, int _y, bool _sex, unsigned short _repro, unsigned short _size, unsigned short _sight, Animal _parents[2], Stat* _health, Stat* _age , Stat* _thirst, Stat* _hunger) {
	position_x = _x;
	position_y = _y;
	sex = _sex; //false = female, true = male;
	size = _size;
	reproduction_age = _repro;
	sight = _sight;
	parents = { _parents[0], _parents[1] };
	health = *_health;
	age = *_age;
	thirst = *_thirst;
	hunger = *_hunger;
}

bool Animal::is_dead() {
	if (health.get_current() <= 0) return true;
	else return false;
}
void Animal::set_x(int _x) {
	position_x = _x;
}
void Animal::set_y(int _y) {
	position_y = _y;
}
void Animal::set_sex(bool _sex) {
	sex = _sex;
}
void Animal::set_sight(unsigned short _sight) {
	sight = _sight;
}
void Animal::set_reproduction(unsigned short _repro) {
	reproduction_age = _repro;
}
void Animal::set_parents(Animal _parent1, Animal _parent2) {
	std::vector<Animal> temp = { _parent1, _parent2 };
	parents = temp;
}
void Animal::set_sprite(std::string _sprite_path) {
	sprite_path = _sprite_path;
}

unsigned short Animal::get_x() {
	return position_x;

}
unsigned short Animal::get_y() {
	return position_y;
}
unsigned short Animal::get_reproduction() {
	return reproduction_age;
}
bool Animal::get_sex() {
	return sex;
}

unsigned short Animal::get_sight() {
	return sight;
}
std::vector<Animal> Animal::get_parents(unsigned int _precision) {
	if (parents.size() >= 2 && _precision > 0)
	{
		std::vector<Animal> parent1 = parents[0].get_parents(_precision -1);
		std::vector<Animal> parent2 = parents[1].get_parents(_precision -1);

		std::vector<Animal> heritage = parents;
		heritage.insert(heritage.end(), parent1.begin(), parent1.end());
		heritage.insert(heritage.end(), parent2.begin(), parent2.end());
		return heritage;
	}
	else {
		std::vector<Animal> empty(0);
		return empty;
	}
}
std::string Animal::get_sprite() {
	return sprite_path;
}






Cat::Cat()
{
}

Cat::~Cat()
{
}
