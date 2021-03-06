/// \file
/// \brief Source file for env_temperature
/// \details Source file for env_temperature environment parameter. Currently only generates temperature, in future will also mix it as time passes.
/// \author Miko³aj Kaczmarek
/// \date 20.05.2020
/// \version 0.10

#include "env_temperature.h"
#include <iomanip>

/// \brief Script generating temperature
/// \author Mikolaj Kaczmarek
/// \date 20.05.2020
/// \version 1.00
///
///Temperature is generated based on previously generated neightbours and amplitude percent set in env_temperature.h.
///In first place generated is block [0, 0], then first line and after that first column. Rest of array use average value from blocks [n-1, m], [n, m-1] and [n-1, m-1].
void env_temperature::generate_temperature(sprite_params** data, int width, int height) {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<> dis(min_temp, max_temp);
	//data[0][0].set_temperature(dis(gen));
	data[0][0].set_temperature(30);

	double temp_change, temp_value, temp_min, temp_max;

	//generate first row
	for (int i = 1; i <= width; i++) {
		temp_value = data[0][i - 1].get_temperature();
		temp_change = (abs(temp_value * change_percent) != 0) ? (abs(temp_value * change_percent)) : 5;

		temp_min = ((temp_value - temp_change) > min_temp) ? (temp_value - temp_change) : min_temp;
		temp_max = ((temp_value + temp_change) < max_temp) ? (temp_value + temp_change) : max_temp;

		std::uniform_real_distribution<> dis(temp_min, temp_max);
		data[0][i].set_temperature(dis(gen));
	}

	//generate first column

	for (int i = 1; i <= height; i++) {
		temp_value = data[i - 1][0].get_temperature();
		temp_change = (abs(temp_value * change_percent) != 0) ? (abs(temp_value * change_percent)) : 5;

		temp_min = ((temp_value - temp_change) > min_temp) ? (temp_value - temp_change) : min_temp;
		temp_max = ((temp_value + temp_change) < max_temp) ? (temp_value + temp_change) : max_temp;

		std::uniform_real_distribution<> dis(temp_min, temp_max);
		data[i][0].set_temperature(dis(gen));
	}

	//generate rest of area

	for (int i = 1; i <= width; i++) {
		for (int j = 1; j <= height; j++) {
			short select_tile = rand() % 3;
			if (select_tile == 0) {
				temp_value = data[i - 1][j].get_temperature();
			}
			else if (select_tile == 1) {
				temp_value = data[i][j - 1].get_temperature();
			}
			else {
				temp_value = data[i - 1][j - 1].get_temperature();
			}
			//temp_value = (data[i - 1][j].get_temperature() + data[i][j - 1].get_temperature() + data[i - 1][j - 1].get_temperature()) / 3;
			//temp_change = (abs(temp_value * change_percent) != 0) ? (abs(temp_value * change_percent)) : 5;
			temp_change = 6;

			temp_min = ((temp_value - temp_change) > min_temp) ? (temp_value - temp_change) : min_temp;
			temp_max = ((temp_value + temp_change) < max_temp) ? (temp_value + temp_change) : max_temp;

			std::uniform_real_distribution<> dis(temp_min, temp_max);
			double tempp = dis(gen);
			data[i][j].set_temperature(tempp);

			//std::cout << std::fixed << std::setprecision(2) << tempp << " ";
		}
		//std::cout << std::endl;
	}
}

/// \brief Function mixing temperature mid-simulation
/// \author Mikolaj Kaczmarek
/// \date 25.06.2020
/// \version 0.30
///
/// Temperature mixing is based on making average value from adjacent fields, assuming SE wind.
/// First mixed is first row with [0][i-1] field, then first column with [i-1][0], then others with [i-1][j], [i][j-1] and [i-1][j-1].
void env_temperature::mix_temperature(sprite_params** data, int width, int height) {
	//generate [0][0]
	data[0][0].set_temperature(((data[0][0].get_temperature() * 5) + data[1][0].get_temperature() + data[1][1].get_temperature() + data[0][1].get_temperature() + data[width][height].get_temperature()) / 9);
	
	//generate first row
	for (int i = 1; i <= width; i++) {
		data[0][i].set_temperature((data[0][i - 1].get_temperature() + (data[0][i].get_temperature()*5)) / 6);
	}

	//generate first column
	for (int i = 1; i <= height; i++) {
		data[i][0].set_temperature((data[i - 1][0].get_temperature() + (data[i][0].get_temperature()*5)) / 6);
	}

	//generate rest of area
	for (int i = 1; i <= width; i++) {
		for (int j = 1; j <= height; j++) {
			data[i][j].set_temperature(((data[i][j].get_temperature()*5) + data[i - 1][j].get_temperature() + data[i - 1][j - 1].get_temperature() + data[i][j - 1].get_temperature()) / 8);
		}
	}

	std::cout << "Temperature mixed" << std::endl;
}