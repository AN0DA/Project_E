#include "env_temperature.h"
#include <iostream>

//ERROR: data -> ACCESS VIOLATION
void env_temperature::generate_temperature(sprite_params** data, int width, int height) {
	std::random_device rd;
	std::mt19937 gen(rd());

	std::uniform_int_distribution<> dis(min_temp, max_temp);
	data[0][0].temperature = dis(gen);

	//generate first row
	for (int i = 1; i < width; i++) {
		std::uniform_int_distribution<> dis((data[0][i - 1].temperature * change_percent), (data[0][i - 1].temperature * (change_percent + 1)));
		data[0][i].temperature = dis(gen);
	}

	//generate first column
	for (int i = 1; i < height; i++) {
		std::uniform_int_distribution<> dis((data[i - 1][0].temperature * change_percent), (data[i - 1][0].temperature * (change_percent + 1)));
		data[i][0].temperature = dis(gen);
	}

	//generate rest of area
	for (int i = 1; i < width; i++) {
		for (int j = 1; i < height; i++) {
			double avg = (data[i - 1][j].temperature + data[i][j - 1].temperature + data[i - 1][j - 1].temperature) / 3;
			std::uniform_int_distribution<> dis((avg * change_percent), (avg * (change_percent + 1)));
			data[i][j].temperature = dis(gen);
		}
	}

	for (int i = 0; i < width; i++) {
		for (int j = 0; i < height; i++) {
			std::cout << data[i][j].temperature << " ";
		}
		std::cout << std::endl;
	}
}