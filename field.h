#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

struct Field
{
	sf::Sprite sprite;
	int x;
	int y;
	int humidity;
	bool isRooted;
	Field* neighbors[4];
};