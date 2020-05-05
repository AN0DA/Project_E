#pragma once
#include "Animal_stats.h"


class Animal
{
public:
	Animal();
	~Animal();

	bool is_dead();

private:

	unsigned short current_health{ 1 };
	unsigned short max_health{ 1 };
	bool cancer{ false };
	unsigned short current_age{ 0 };
	unsigned short max_age{ 0 };






};

class Cat : public Animal
{
public:
	Cat();
	~Cat();

private:

};

