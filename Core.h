#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "world_gen.h"

class Core {
public:
	int GenerateRandomInt(int a);
};

class sprite_params {
	double temperature = 0;
	
	int x;
	int y;
	int humidity;
	bool isRooted;
public:
	sf::Sprite sprite;
	sprite_params();
	void set_temperature(double _temperature);
	double get_temperature();
	sf::Sprite getSprite();
	int getX();
	int getY();
	int getHumidity();
	void setHumidity(int newHumidity);
	bool getRootStatus();
	void setRootStatus(bool newStatus);
	sprite_params* neighbors[4];
};
