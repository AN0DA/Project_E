#include "env_humidity.h"
#include <cmath>


void env_humidity::generate_desert(sprite_params** data, int width, int height, int coordX, int coordY) {
	for (int i = coordX; i < height; i++) {
		int left = rand() % (width / 3);
		int right = rand() % (width / 3);
		for (int j = (width / 3) - left; j < ((width / 3) * 2) + right - 1; j++) {
			//std::cout << i << " " << j<<" N: ";
			data[i][j].setHumidity(10);
		}
		//std::cout << std::endl;
	}
}

void env_humidity::generate_lake(sprite_params** data, int coordX, int coordY, int radius) {
	sprite_params center = data[coordX][coordY];
	for (int i = coordX-radius; i <= coordX+radius; i++) {
		for (int j = coordY-radius; j <= coordY + radius; j++) {
			if (sqrt(((coordX - i)*(coordX-i)) + ((coordY - j)*(coordY-j))) <= radius) {
				data[i][j].setWater(true);
				std::cout << i << " " << j<<" N: ";
			}
		}
		std::cout << std::endl;
	}
}
void env_humidity::generate_river(sprite_params** data, int width, int height) {
	int river_top_start = 1 + (std::rand() % (width - 1));
	int river_turn =(height/10)+ (std::rand() % (height - (height/10)));
	int turn_length = 1 + (std::rand() % (width - 1) / 5);
	int new_river;
	bool side = river_top_start > (width / 2); //true=lewo,false=prawo


	for (int i = 0; i < river_turn; i++) {
		data[i][river_top_start].setWater(true);
	}
	if (side) {
		//lewo
		for (int j = river_top_start; j > (river_top_start - turn_length); j--) {
			data[river_turn][j].setWater(true);
		}
		//nowe miejsce rzeki
		new_river = river_top_start - turn_length;

	}

	else {
		//prawo
		for (int j = river_top_start; j < (river_top_start + turn_length); j++) {
			data[river_turn][j].setWater(true);
		}
		//nowe miejsce rzeki
		new_river = river_top_start + turn_length;
	}

	for (int i = river_turn; i <= height; i++) {
		data[i][new_river].setWater(true);
	}
}
void env_humidity::generate_humidity(sprite_params** data, int width, int height) {
	generate_river(data,  width,  height);
	int desert_width = 3 + (rand() % ((width * 2 / 3)));
	int desert_height = 3 + (rand() % ((height * 2 / 3)));
	int desert_coordX = rand() % (width - desert_width - 1);
	int desert_coordY = rand() % (height - desert_height - 1);
	std::cout << desert_width << "   " << desert_height << "   " << desert_coordX << "   " << desert_coordY << std::endl;
	generate_desert(data,desert_width,desert_height,desert_coordX,desert_coordY);
	int lake_number = 1+ (rand() % (std::max(width, height) / 20));
	while (lake_number >= 0) {
		int lake_center_coordX = rand() % width;
		int lake_center_coordY = rand() % height;	
		int lake_radius = 1 + (rand() % (std::min(width, height) / 10));
		while (lake_center_coordX + lake_radius >= width || lake_center_coordX - lake_radius <= 0 || lake_center_coordY + lake_radius >= height || lake_center_coordY - lake_radius <= 0) {
			std::cout << lake_radius<<std::endl;
			lake_radius = rand() % (std::min(width, height) / 10);
		}
		generate_lake(data, lake_center_coordX, lake_center_coordY, lake_radius);
		lake_number--;
	}
}
/*
	if (side) {
		//LEWO

		//potrzebny wiersz
		for (int j = river_top_start - turn_length - 1; j >= 0; j--) {
			humidty_value = data[river_turn][j + 1].getHumidity() - (1 + rand() % 4);
			data[river_turn][j].setHumidity(humidty_value);
		}

		for (int j = river_top_start + 1; j <= width; j++) {\
			humidty_value = data[river_turn][j - 1].getHumidity() - (1 + rand() % 4);
			data[river_turn][j].setHumidity(humidty_value);
		}
		
		//æwiartka NW
		for (int i = river_turn - 1; i >= 0; i--) {
			for (int j = river_top_start - 1; j >= 0; j--) {
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
		for (int j = river_top_start + turn_length + 1; j <= width; j++) {
			humidty_value = data[river_turn][j - 1].getHumidity() - (1 + rand() % 4);
			data[river_turn][j].setHumidity(humidty_value);
		}
		for (int j = river_top_start - 1; j >= 0; j--) {
			humidty_value = data[river_turn][j + 1].getHumidity() - (1 + rand() % 4);
			data[river_turn][j].setHumidity(humidty_value);
		}

		//æwiartka NW
		for (int i = river_turn - 1 ; i >=0; i--) {
			for (int j = river_top_start - 1; j >=0; j--) {
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
	/*
	for (int i = 0; i < width; i++) {
		std::cout << "RZ¥D: " << i << std::endl;
		for (int j = 0; j < height; j++) {
			std::cout << data[i][j].getHumidity() << "  ";
		}
		std::cout << std::endl;
	}
	/

}
*/