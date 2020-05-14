#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <random>
#include "Core.h"
#include "field.h"



const int x = 50;
const int y = 20;
bool mustgenthisforfucksake = true;
int Core::GenerateRandomInt(int a) {
	if (mustgenthisforfucksake)

		srand((unsigned)time(NULL));
	mustgenthisforfucksake = false;
	return rand() % a + 1;
}
void Core::SafeToFileBiomeMap(std::string name,Field**d_f) {
	std::ofstream file;
	file.open(name);
	for(int i =0;i<x;i++)
		for (int j = 0; j < y; j++)
		{
			{

	file << d_f[i][j].biome_num;
			}
			file << "\n";
		}
	file.close();
}

void Core::ReadFromFileBiomeMap(std::string name, Field** d_f) {
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
				if (str_d[j]==0)
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
sprite_params::sprite_params() {
	temperature = 0;
}
int sprite_params::getX() {
	return this->x;
}
int sprite_params::getY() {
	return this->y;
}
int sprite_params::getHumidity() {
	return this->humidity;
}
void sprite_params::setHumidity(int newHumidity) {
	this->humidity = newHumidity;
}
bool sprite_params::getRootStatus() {
	return this->isRooted;
}
void sprite_params::setRootStatus(bool newStatus) {
	this->isRooted = newStatus;
}
int sprite_params::getBiome() {
	return this->biome;
}
void sprite_params::setBiome(Biomes biome) {
	this->biome = biome;
}