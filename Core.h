#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "world_gen.h"
#include <iostream>
#include "field.h"


enum class Biomes {
	water,		// temp 0+;			water = true		id:0
	ice,		// temp -10 - 0;	water = true		id:1
	swamp,		//					wilg  85+			id:2
	rainforest, // temp 25 - 35;	wilg  70-85			id:3
	desert,		// temp 25 - 35;	wilg  20-0			id:4
	savanna,	// temp 25 - 35							id:5
	grassland,	// temp 1 - 24							id:6
	snow		// temp -10 - 0							id:7
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
	bool water = false;//false = l¹d, //true = woda
	int temperature = (rand()%46)-10;
	double humidity = 40;
	int x;
	int y;
	bool isRooted;
	Biomes biome;
public:
	sf::Sprite sprite;
	bool isWater();
	void setWater(bool w);
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

