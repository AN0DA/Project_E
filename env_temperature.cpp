#include "env_temperature.h"

const int min_temp = -10; ///< Lowest temperature that can be generated
const int max_temp = 35; ///< Highest temperature that can be generated
const double change_percent = 0.2; ///< Max temperature amplitude percent, that can occur in adjacent blocks. It should be in range <0, 1).

///Script generating temperature
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