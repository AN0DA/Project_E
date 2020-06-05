#include "env_pressure.h"
#include <cmath>
#include <iostream>

void env_pressure::generate_pressure(sprite_params** data, int width, int height) {
	for (int iter = 0; iter < floor(width * height / 80); iter++) {
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

void env_pressure::simulate_wind(sprite_params** data, int width, int height) {
	double temp0_0 = data[0][0].get_pressure();
	double dif0_0[2]; // 00 - 01, 00 - 10
	dif0_0[0] = temp0_0 - data[0][1].get_pressure();
	dif0_0[1] = temp0_0 - data[1][0].get_pressure();

	if (abs(dif0_0[0]) > abs(dif0_0[1])) {
		if (dif0_0[0] < 0) {

		}
		else {

		}
	}



	double temp_change, temp_value, temp_min, temp_max;

	//generate first row
	for (int i = 1; i < width; i++) {
		temp_value = data[0][i - 1].get_temperature();
		temp_change = abs(temp_value * change_percent);

		temp_min = ((temp_value - temp_change) > min_temp) ? (temp_value - temp_change) : min_temp;
		temp_max = ((temp_value + temp_change) < max_temp) ? (temp_value + temp_change) : max_temp;

		std::uniform_real_distribution<> dis(temp_min, temp_max);
		data[0][i].set_temperature(dis(gen));
	}

	//generate first column
	for (int i = 1; i < height; i++) {
		temp_value = data[i - 1][0].get_temperature();
		temp_change = abs(temp_value * change_percent);

		temp_min = ((temp_value - temp_change) > min_temp) ? (temp_value - temp_change) : min_temp;
		temp_max = ((temp_value + temp_change) < max_temp) ? (temp_value + temp_change) : max_temp;

		std::uniform_real_distribution<> dis(temp_min, temp_max);
		data[i][0].set_temperature(dis(gen));
	}

	//generate rest of area
	for (int i = 1; i < width; i++) {
		for (int j = 1; j < height; j++) {
			temp_value = (data[i - 1][j].get_temperature() + data[i][j - 1].get_temperature() + data[i - 1][j - 1].get_temperature()) / 3;
			temp_change = abs(temp_value * change_percent);

			temp_min = ((temp_value - temp_change) > min_temp) ? (temp_value - temp_change) : min_temp;
			temp_max = ((temp_value + temp_change) < max_temp) ? (temp_value + temp_change) : max_temp;

			std::uniform_real_distribution<> dis(temp_min, temp_max);
			data[i][j].set_temperature(dis(gen));
		}
	}
}
