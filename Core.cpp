#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <random>
#include "Core.h"



const int x = 50;
const int y = 20;
bool mustgenthisforfucksake = true;
int Core::GenerateRandomInt(int a) {
	if (mustgenthisforfucksake)


		srand((unsigned)time(NULL));
	mustgenthisforfucksake = false;
	return rand() % a + 1;
}


void Core::SaveToFileBiomeMap(std::string name, sprite_params** d_f) {
	std::ofstream file;
	file.open(name);
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			{
				file << d_f[i][j].getBiome();
			}
			file << std::endl;
		}
	file.close();
}


void Core::ReadFromFileBiomeMap(std::string name, sprite_params** d_f) {
	//std::ofstream file;
	std::ifstream file;
	//std::ifstream input(name);
	file.open(name);
	sf::Texture sand;
	sand.loadFromFile("textures/sand2.jpg");
	sf::Texture sawannah;
	sawannah.loadFromFile("textures/sawannah.jpg");
	sf::Texture snow;
	snow.loadFromFile("textures/snow.jpg");
	sf::Texture grass;
	grass.loadFromFile("textures/grass.jpg");
	char* str_d;
	str_d = new char[x];
	file.getline(str_d, 0);
	for (int i = 0; i < x; i++)
		for (int j = 0; j < y; j++)
		{
			{
				if (str_d[j] == 0)
				{
					d_f[i][j].sprite.setTexture(grass);
				}
				else if (str_d[j] == 1)
				{
					d_f[i][j].sprite.setTexture(sawannah);
				}
				else if (str_d[j] == 2)
				{
					d_f[i][j].sprite.setTexture(snow);
				}
				else if (str_d[j] == 3)
				{
					d_f[i][j].sprite.setTexture(sand);
				}

			}
			file.getline(str_d, i);
		}
}

void  sprite_params::set_temperature(double _temperature) {
	temperature = _temperature;
}
double sprite_params::get_temperature() {
	return temperature;
}

bool sprite_params::isWater() {
	return this->water;
}
sprite_params::sprite_params() = default;

void sprite_params::setWater(bool w) {
	this->water = w;

}
int sprite_params::getX() {
	return this->x;
}
int sprite_params::getY() {
	return this->y;
}
double sprite_params::getHumidity() {
	return this->humidity;
}
void sprite_params::setHumidity(double newHumidity) {
	this->humidity = newHumidity;
}

double sprite_params::get_pressure() {
	return this->pressure;
}
void sprite_params::set_pressure(double _pressure)
{
	this->pressure = _pressure;
}
bool sprite_params::getRootStatus() {
	return this->isRooted;
}
void sprite_params::setRootStatus(bool newStatus) {
	this->isRooted = newStatus;
}
Biomes sprite_params::getBiome() {
	return this->biome;
}
void sprite_params::setBiome(Biomes newBiome) {
	this->biome = newBiome;
}
