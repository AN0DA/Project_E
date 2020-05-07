#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

struct Field
{
	sf::Sprite sprite;
	int x;
	int y;
	int humidity;
	bool isRooted;
	Field* neighbors[4];
};