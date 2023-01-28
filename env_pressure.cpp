#include "env_pressure.h"


/// \brief Function generating environment pressure cyclons
/// \author Mikolaj Kaczmarek
/// \date 17.05.2020
/// \version 0.20
///
/// Pressure generator is based on generating positive or negative currents in shape of circles.
/// Pressure can vary from 980 to 1040.
void env_pressure::generate_pressure(sprite_params** data, int width, int height) {
	for (int iter = 0; iter < floor(width * height / 55); iter++) {
	//for (int iter = 0; iter < 5; iter++) {
		int current_height = rand() % height;
		int current_width = rand() % width;
		int radius = rand() % 12;

		int pressure_change = rand() % 61 + 980;
		double change_per_block;


		int temp = 0;
		for (int i = std::max((current_width - radius), 0); i <= std::min((current_width + radius), width); i++) {
			for (int j = std::max((current_height - radius), 0); j <= std::min((current_height + radius), height); j++) {
				if (sqrt(((current_width - i) * (current_width - i)) + ((current_height - j) * (current_height - j))) <= radius) {
					temp++;
				}
			}
		}

		if (pressure_change > data[current_width][current_height].get_pressure()) {
			change_per_block = (pressure_change - data[current_width][current_height].get_pressure()) / temp;
		}
		else if (pressure_change < data[current_width][current_height].get_pressure()) {
			change_per_block = ((data[current_width][current_height].get_pressure() - pressure_change) / temp) * -1;
		}
		else
			continue;


	
		double value = data[current_width][current_height].get_pressure();
		for (int i = std::max((current_width - radius), 0); i <= std::min((current_width + radius), width); i++) {
			for (int j = std::max((current_height - radius), 0); j <= std::min((current_height + radius), height); j++) {
				if (sqrt(((current_width - i) * (current_width - i)) + ((current_height - j) * (current_height - j))) <= radius) {
					value = value + change_per_block;
					data[i][j].set_pressure(value);
				}
			}
		}
	}
}

/// \brief CURRENTLY NOT USED Function regenerating environment pressure cyclons
/// \author Mikolaj Kaczmarek
/// \date 19.05.2020
/// \version 0.01
void env_pressure::regenerate_pressure(sprite_params** data, int width, int height, int iterations) {
	for (int iter = 0; iter < iterations; iter++) {
		int current_height = rand() % height;
		int current_width = rand() % width;
		int radius = rand() % 5;

		int pressure_change = rand() % 70 + 980;
		double change_per_block;


		int temp = 0;
		for (int i = std::max((current_width - radius), 0); i <= std::min((current_width + radius), width); i++) {
			for (int j = std::max((current_height - radius), 0); j <= std::min((current_height + radius), height); j++) {
				if (sqrt(((current_width - i) * (current_width - i)) + ((current_height - j) * (current_height - j))) <= radius) {
					temp++;
				}
			}
		}

		if (pressure_change > data[current_width][current_height].get_pressure()) {
			change_per_block = (pressure_change - data[current_width][current_height].get_pressure()) / temp;
		}
		else if (pressure_change < data[current_width][current_height].get_pressure()) {
			change_per_block = ((data[current_width][current_height].get_pressure() - pressure_change) / temp) * -1;
		}
		else
			continue;



		double value = data[current_width][current_height].get_pressure();
		for (int i = std::max((current_width - radius), 0); i <= std::min((current_width + radius), width); i++) {
			for (int j = std::max((current_height - radius), 0); j <= std::min((current_height + radius), height); j++) {
				if (sqrt(((current_width - i) * (current_width - i)) + ((current_height - j) * (current_height - j))) <= radius) {
					value = value + change_per_block;
					data[i][j].set_pressure(value);
				}
			}
		}
	}
}