#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "world_gen.h"
#include <iostream>
#include "field.h"
class Core {
public:
	int GenerateRandomInt(int a);
	void SafeToFileBiomeMap(std::string name, Field** d_f);
	void ReadFromFileBiomeMap(std::string name, Field** d_f);
};

class sprite_params {
	double temperature = 0;
	
	int x;
	int y;
	int humidity;
	bool isRooted;
	Biomes biome;
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
	void setBiome(Biomes biome);
	int getBiome();

	sprite_params* neighbors[4];
};


enum Biomes {
	water,		// temp 0+;			wilg = 100
	ice,		// temp 0-;			wilg = 100
	rainforest, // temp 25 - 35;	wilg  80-100
	desert,		// temp 25 - 35;	wilg  20-0
	savanna,	// temp 16 - 26
	grassland,	// temp 1 - 15
	snow		// temp -10 - 0
};