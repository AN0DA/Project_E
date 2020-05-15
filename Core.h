#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "world_gen.h"
#include <iostream>
#include "field.h"


enum class Biomes {
	water,		// temp 0+;			wilg = 100			id:0
	ice,		// temp 0-;			wilg = 100			id:1
	rainforest, // temp 25 - 35;	wilg  80-100		id:2
	desert,		// temp 25 - 35;	wilg  20-0			id:3
	savanna,	// temp 25 - 35							id:4
	grassland,	// temp 1 - 24							id:5
	snow		// temp -10 - 0							id:6
};
template<typename T>
std::ostream& operator<<(typename std::enable_if<std::is_enum<T>::value, std::ostream>::type& stream, const T& e)
{
	return stream << static_cast<typename std::underlying_type<T>::type>(e);
}


class Core {
public:
	int GenerateRandomInt(int a);
	void SafeToFileBiomeMap(std::string name, Field** d_f);
	void ReadFromFileBiomeMap(std::string name, Field** d_f);
};

class sprite_params {
	double temperature = 0;
	double humidity;
	int x;
	int y;
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
	double getHumidity();
	void setHumidity(double newHumidity);
	bool getRootStatus();
	void setRootStatus(bool newStatus);
	void setBiome(Biomes biome);
	Biomes getBiome();

	sprite_params* neighbors[4];
};

