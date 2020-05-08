/*
#pragma once
#include <iostream>
#include "world_gen.h"
#include "env_gen.h"
#include "Core.h"

void world_gen::generate_world(sf::Window* window, env_gen environment_gen)
{
    //texture init for landscape
    sf::Texture sand;
    if (!sand.loadFromFile("textures/sand.png"))
    {
        std::cout << "Sand isn't loaded!";
    }
    sf::Texture sawannah;
    if (!sand.loadFromFile("textures/sawannah.png"))
    {
        std::cout << "Sand isn't loaded!";
    }
    sf::Texture snow;
    if (!snow.loadFromFile("textures/snow.png"))
    {
        std::cout << "snow isn't loaded!";
    }
    sf::Texture grass;
    if (!grass.loadFromFile("textures/grass.png"))
    {
        std::cout << "Grass isn't loaded!";
    }
    //end of lodin
	sf::Sprite sprites[500][500];
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			//sprite.setColor(sf::Color(rand, rand, rand));				TO DO!
			sprites[i][j].setTexture(grass);
			sprites[i][j].setPosition(sf::Vector2f(i, j));
			//window->setVisible();
			window->display();//draw(sprites[i][j]);

		}
	}
}
*/