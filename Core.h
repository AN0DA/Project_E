#pragma once
#include <SFML/Graphics.hpp>
#include "world_gen.h"
#include <SFML/Window.hpp>
class Core
{

public:
    int GenerateRandomInt(int a);
};


class sprite_params {

public:
    sprite_params();

    void set_temperature(double _temperature);
    double get_temperature();

private:
    double temperature = 0;
};

