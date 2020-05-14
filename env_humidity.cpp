#include "env_humidity.h"

void env_humidity::generate_humidity(sprite_params** data, int width, int height) {
	int river_top_start = std::rand() % width;
	int river_turn = 5 + (std::rand() % height - 10);
	int turn_length = 1+ (std::rand() % (width - 1) / 5);
	int new_river;
	int humidty_value;
	bool side = river_top_start > (width / 2); //true=lewo,false=prawo

	for (int i = 0; i < river_turn; i++) {
		data[i][river_top_start].setHumidity(100);
	}
	if (side) {
		//lewo

		//rzeka
		for (int i = river_top_start; i > river_top_start-turn_length; i--) {
			data[river_turn][i].setHumidity(100);
		}
	}


	else {
		//prawo
		for (int i = river_top_start; i < river_top_start + turn_length; i++) {
			data[river_turn][i].setHumidity(100);
		}
	}

	//nowe miejsce rzeki
	new_river = river_top_start + turn_length;


	for (int i = river_turn; i <= height; i++) {
		data[i][new_river];
	}


	if (side) {
		//LEWO

		//potrzebny wiersz
		for (int i = river_top_start - turn_length - 1; i >= 0; i--) {
			humidty_value = data[river_turn][i + 1].getHumidity() - (1 + rand() % 4);
			data[river_turn][i].setHumidity(humidty_value);
		}
		for (int i = river_top_start + 1; i < width; i++) {
			humidty_value = data[river_turn][i - 1].getHumidity() - (1 + rand() % 4);
			data[river_turn][i].setHumidity(humidty_value);
		}
		
		//æwiartka NW
		for (int i = river_turn - 1; i >= 0; i--) {
			for (int j = river_top_start - 1; i >= 0; i--) {
				humidty_value = ((data[i + 1][j].getHumidity() + data[i][j + 1].getHumidity()) / 2) - (1 + rand() % 4);
				data[i][j].setHumidity(humidty_value);
			}
		}

		//æwiartka NE
		for (int i = river_turn - 1; i >= 0; i--) {
			for (int j = river_top_start + 1; j <= width; j++) {
				humidty_value = ((data[i + 1][j].getHumidity() + data[i][j - 1].getHumidity()) / 2) - (1 + rand() % 4);
				data[i][j].setHumidity(humidty_value);
			}
		}

		//æwiartka SE
		for (int i = river_turn + 1; i <= height; i++) {
			for (int j = new_river + 1; j <= width; j++) {
				humidty_value = ((data[i - 1][j].getHumidity() + data[i][j - 1].getHumidity()) / 2) - (1 + rand() % 4);
				data[i][j].setHumidity(humidty_value);
			}
		}

		//æwiartka SW
		for (int i = river_turn + 1; i <= height; i++) {
			for (int j = new_river - 1; j >= 0; j--) {
				humidty_value = ((data[i - 1][j].getHumidity() + data[i][j + 1].getHumidity()) / 2) - (1 + rand() % 4);
				data[i][j].setHumidity(humidty_value);
			}
		}
		
	}
	else {
		//PRAWO

		//Potrzebny wiersz
		for (int i = river_top_start + turn_length - 1; i < width; i++) {
			humidty_value = data[river_turn][i - 1].getHumidity() - (1 + rand() % 4);
			data[river_turn][i].setHumidity(humidty_value);
		}
		for (int i = river_top_start - 1; i > 0; i--) {
			humidty_value = data[river_turn][i + 1].getHumidity() - (1 + rand() % 4);
			data[river_turn][i].setHumidity(humidty_value);
		}

		//æwiartka NW
		for (int i = river_turn - 1 ; i >=0; i--) {
			for (int j = river_top_start - 1; i >=0; i--) {
				humidty_value = ((data[i + 1][j].getHumidity() + data[i][j + 1].getHumidity()) / 2) - (1 + rand() % 4);
				data[i][j].setHumidity(humidty_value);  
			}
		}

		//æwiartka NE
		for (int i = river_turn - 1; i >= 0; i--) {
			for (int j = river_top_start + 1; j <= width; j++) {
				humidty_value = ((data[i + 1][j].getHumidity() + data[i][j - 1].getHumidity()) / 2) - (1 + rand() % 4);
				data[i][j].setHumidity(humidty_value);
			}
		}

		//æwiartka SE
		for (int i = river_turn + 1; i <= height; i++) {
			for (int j = new_river + 1; j <= width; j++) {
				humidty_value = ((data[i - 1][j].getHumidity() + data[i][j - 1].getHumidity()) / 2) - (1 + rand() % 4);
				data[i][j].setHumidity(humidty_value);
			}
		}

		//æwiartka SW
		for (int i = river_turn + 1; i <= height; i++) {
			for (int j = new_river - 1; j >= 0; j--) {
				humidty_value = ((data[i - 1][j].getHumidity() + data[i][j + 1].getHumidity()) / 2) - (1 + rand() % 4);
				data[i][j].setHumidity(humidty_value);
			}
		}
	}

	//TEST
	for (int i = 0; i < width; i++) {
		for (int j = 0; i < height; i++) {
			std::cout << data[i][j].getHumidity() << " ";
		}
		std::cout << std::endl;
	}

}