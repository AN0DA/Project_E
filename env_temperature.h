/// \headerfile
/// \brief Header file for env_temperature
/// \details Header file for env_temperature environment parameter. Currently only generates temperature, in future will also mix it as time passes.
/// \date 20.05.2020
/// \author Mikolaj Kaczmarek
/// \version 0.10

#pragma once
#include <cmath>
#include <random>
#include "Core.h"


/// 
class env_temperature
{
	/// \class env_temperature env_temperature.h
	/// \brief Class related to environment temperature simulation.

	
	/// Lowest temperature that can be generated
	const int min_temp = -10; 
	/// Highest temperature that can be generated
	const int max_temp = 35; 
	/// Max temperature amplitude percent, that can occur in adjacent blocks. It should be in range <0, 1).
	const double change_percent = 0.2; 

public:
	/// Fuction that generates tempeature for the first time
	///
	/// \param data sprite_params array passed from main
	/// \param width sprite_params array width
	/// \param height sprite_params array height
	void generate_temperature(sprite_params** data, int width, int height);
};
