#include "env_humidity.h"

void env_humidity::generate_humidity(sprite_params** data, int width, int height) {
	int river_top_start = std::rand() % width;
	int river_turn = 5 + (std::rand() % height - 10);
	int turn_length = (std::rand() % width / 5);
	int new_river;

	for (int i = 0; i < river_turn; i++) {
		data[i][river_top_start].setHumidity(100);
	}
	if (river_top_start > width / 2) {
		//lewo
		for (int i = river_top_start; i > river_top_start-turn_length; i--) {
			data[river_turn][i].setHumidity(100);
		}
		new_river = river_top_start - turn_length;
	}


	else {
		//prawo
		for (int i = river_top_start; i < river_top_start + turn_length; i++) {
			data[river_turn][i].setHumidity(100);
		}
		new_river = river_top_start + turn_length;
	}


	for (int i = river_turn; i <= height; i++) {
		data[i][new_river];
	}
}