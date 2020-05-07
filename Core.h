#pragma once
#include <SFML/Graphics.hpp>
#include "world_gen.h"
#include <SFML/Window.hpp>
class Core
{
struct sprite_params{
double temperature;
}; 
public:
    int GenerateRandomInt(int a);
};

