/// \file
/// \brief Source file for env_temperature
/// \details Source file for env_temperature environment parameter. Currently only generates temperature, in future will also mix it as time passes.
/// \author Miko³aj Kaczmarek
/// \date 20.05.2020
/// \version 0.10

#include "env_temperature.h"

/// \brief Script generating temperature
/// \author Miko³aj Kaczmarek
/// \date 20.05.2020
/// \version 0.10
///
///Temperature is generated based on previously generated neightbours and amplitude percent set in env_temperature.h.
///In first place generated is block [0, 0], then first line and after that first column. Rest of array use average value from blocks [n-1, m], [n, m-1] and [n-1, m-1].
void env_temperature::generate_temperature(sprite_params** data, int width, int height) {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_real_distribution<> dis(min_temp, max_temp);
	data[0][0].set_temperature(dis(gen));

	double temp_change, temp_value, temp_min, temp_max;

	//generate first row
	for (int i = 1; i <= width; i++) {
		temp_value = data[0][i - 1].get_temperature();
		temp_change = (abs(temp_value * change_percent) != 0) ? (abs(temp_value * change_percent)) : 10;

		temp_min = ((temp_value - temp_change) > min_temp) ? (temp_value - temp_change) : min_temp;
		temp_max = ((temp_value + temp_change) < max_temp) ? (temp_value + temp_change) : max_temp;

		std::uniform_real_distribution<> dis(temp_min, temp_max);
		data[0][i].set_temperature(dis(gen));
	}

	//generate first column
	for (int i = 1; i <= height; i++) {
		temp_value = data[i - 1][0].get_temperature();
		temp_change = (abs(temp_value * change_percent) != 0) ? (abs(temp_value * change_percent)) : 10;

		temp_min = ((temp_value - temp_change) > min_temp) ? (temp_value - temp_change) : min_temp;
		temp_max = ((temp_value + temp_change) < max_temp) ? (temp_value + temp_change) : max_temp;

		std::uniform_real_distribution<> dis(temp_min, temp_max);
		data[i][0].set_temperature(dis(gen));
	}

	//generate rest of area
	for (int i = 1; i <= width; i++) {
		for (int j = 1; j <= height; j++) {
			temp_value = (data[i - 1][j].get_temperature() + data[i][j - 1].get_temperature() + data[i - 1][j - 1].get_temperature()) / 3;
			temp_change = (abs(temp_value * change_percent) != 0) ? (abs(temp_value * change_percent)) : 10;

			temp_min = ((temp_value - temp_change) > min_temp) ? (temp_value - temp_change) : min_temp;
			temp_max = ((temp_value + temp_change) < max_temp) ? (temp_value + temp_change) : max_temp;

			std::uniform_real_distribution<> dis(temp_min, temp_max);
			data[i][j].set_temperature(dis(gen));
		}
	}
}

void env_temperature::mix_temperature(sprite_params** data, int width, int height) {
	//generate first row
	for (int i = 1; i <= width; i++) {
		data[0][i].set_temperature((data[0][i - 1].get_temperature() + data[0][i].get_temperature()) / 2);
	}

	//generate first column
	for (int i = 1; i <= height; i++) {
		data[i][0].set_temperature((data[i - 1][0].get_temperature() + data[i][0].get_temperature()) / 2);
	}

	//generate rest of area
	for (int i = 1; i <= width; i++) {
		for (int j = 1; j <= height; j++) {
			data[i][j].set_temperature((data[i][j].get_temperature() + data[i - 1][j].get_temperature() + data[i - 1][j - 1].get_temperature() + data[i][j - 1].get_temperature()) / 4);
		}
	}

	std::cout << "Temperature mixed" << std::endl;
}