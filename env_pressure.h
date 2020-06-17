#pragma once
#include "Core.h"
#include <cmath>
#include <iostream>


class env_pressure {
public:
	/// Fuction that generates pressure cyclons
///
/// \param data sprite_params array passed from main
/// \param width sprite_params array width
/// \param height sprite_params array height
	void generate_pressure(sprite_params** data, int width, int height);

	/// CURRENTLY NOT USED Fuction that regenerates pressure cyclons 
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	void regenerate_pressure(sprite_params** data, int width, int height, int iterations = NULL);

};