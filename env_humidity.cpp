/// \file
/// \brief Source file for env_humidity
/// \details Source file for env_humidity environment parameter. Generates river, lakes and humidity around them.
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1

#include "env_humidity.h"
#include <cmath>


/// \brief Script creating water tile
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1
///
/// function creates sets water and calls circle_humidity() to generate humidity
void env_humidity::create_water_tile(sprite_params** data, int width, int height, int coordX, int coordY, int humidity_reach) {
	if (!data[coordX][coordY].isWater()) {
		data[coordX][coordY].setWater(true);
		circle_humidity(data, width, height, coordX, coordY, humidity_reach);
	}
	// debug print if a tile would be generated twice
	else {
		//std::cout << coordX << "    " << coordY << std::endl;
	}
}


/// \brief Script generating desert tiles
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1
///
/// function generates random amunt of desert tiles in each row, at minimum width/3
void env_humidity::generate_desert(sprite_params** data, int width, int height, int coordX, int coordY) {
	for (int i = coordX; i < height; i++) {
		int left = rand() % (width / 3);
		int right = rand() % (width / 3);
		for (int j = (width / 3) - left; j < ((width / 3) * 2) + right - 1; j++) {
			data[i][j].setHumidity(10);
		}
	}
}


/// \brief Script creating lakes
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1
///
/// function creates circular lakes by checking if the distance beetween a tile and the center of a lake is smaller than the radius, if yes then it creates a water tile there
void env_humidity::generate_lake(sprite_params** data,int width,int height, int coordX, int coordY, int radius) {
	for (int i = std::max((coordX - radius), 0); i <= std::min((coordX + radius), width); i++) {
		for (int j = std::max((coordY - radius), 0); j <= std::min((coordY + radius), height); j++) {
			if (sqrt(((coordX - i) * (coordX - i)) + ((coordY - j) * (coordY - j))) <= radius) {
				create_water_tile(data, width, height, i, j, radius * 2);
			}
		}
	}
}


/// \brief Script adding humidity
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1
///
/// function adds humidity value in a circle by checking if the distance beetween a tile and the center of a lake is smaller than the radius, if yes then it creates a water tile there
void env_humidity::circle_humidity(sprite_params** data, int width, int height, int coordX, int coordY, int radius) {
	double temp_hum;
	for (int i = std::max((coordX - radius),0); i <= std::min((coordX + radius),width); i++) {
		for (int j = std::max((coordY - radius), 0); j <= std::min((coordY + radius), height); j++) {
			if (sqrt(((coordX - i) * (coordX - i)) + ((coordY - j) * (coordY - j))) <= radius) {
				temp_hum = data[i][j].getHumidity() + (data[i][j].getHumidity() +1)* 0.01;
				data[i][j].setHumidity(temp_hum);
			}
		}
	}
}



/// \brief Script creating a river 
/// \author Konstanty Kordas
/// \date 27.05.2020
/// \version 0.1
///
/// function generates a river
void env_humidity::generate_river(sprite_params** data, int width, int height, int coordX, int coordY, int river_width,int river_turn) {
	int turn_length = (river_width * 2) + (std::rand() % (width / 2 - (river_width * 4)));	//length of the sideways running river,generated so it will always fit inside the grid
	bool side = coordX > (width / 2);	//true=left,false=right

if (side) {
	//turn goes left


	//river going from beginning to the turn
	for (int j = coordY; j < river_turn; j++) {
		for (int i = coordX - river_width; i <= coordX; i++) {
			create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2, 7));
		}
	}


	//top-left turn
	for (int j = river_turn; j <= river_turn + river_width; j++) {
		for (int i = coordX - river_width; i <= coordX; i++) {
			if (sqrt(((coordX - river_width - i) * (coordX - river_width - i)) + ((river_turn - j) * (river_turn - j))) <= river_width) {
				create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2,7));
			}
		}
	}


	//sideways river
	for (int j = river_turn; j <= river_turn + river_width; j++) {
		for (int i = coordX - river_width - turn_length; i < coordX - river_width; i++) {
			create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2,7));
		}
	}


	//right-down turn
	for (int j = river_turn; j <= river_turn + river_width; j++) {
		for (int i = coordX - river_width - turn_length - river_width; i < coordX - river_width - turn_length; i++) {
			if (sqrt(((coordX - river_width - turn_length - i) * (coordX - river_width - turn_length - i)) + ((river_turn + river_width - j) * (river_turn + river_width - j))) <= river_width) {
				create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2,7));
			}
		}
	}


	//river going down from turn to the end of the grid
	for (int j = river_turn + river_width+1; j < height; j++) {
		for (int i = coordX - river_width - turn_length - river_width; i <= coordX - river_width - turn_length; i++) {
			create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2,7));
		}
	}
}
else {
	//turn goes right


	//river going from beginning to the turn
	for (int j = coordY; j < river_turn; j++) {
		for (int i = coordX; i <= coordX + river_width; i++) {
			create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2,7));
		}
	}


	//top-right turn
	for (int j = river_turn; j <= river_turn + river_width; j++) {
		for (int i = coordX; i < coordX + river_width; i++) {
			if (sqrt(((coordX + river_width - i) * (coordX + river_width - i)) + ((river_turn - j) * (river_turn - j))) <= river_width) {
				create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2, 7));
			}
		}
	}


	//sideways river
	for (int j = river_turn; j <= river_turn + river_width; j++) {
		for (int i = coordX + river_width; i < coordX + river_width + turn_length; i++) {
			create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2,7));
		}
	}


	//left-down turn
	for (int j = river_turn; j < river_turn + river_width; j++) {
		for (int i = coordX + river_width + turn_length; i <= coordX + river_width + turn_length + river_width; i++) {
			if (sqrt(((coordX + river_width + turn_length - i) * (coordX + river_width + turn_length - i)) + ((river_turn + river_width - j) * (river_turn + river_width - j))) <= river_width) {
				create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2,7));
			}
		}
	}


	//river going down from turn to the end of the grid
	for (int j = river_turn + river_width; j <= height; j++) {
		for (int i = coordX + river_width + turn_length; i <= coordX + +river_width + turn_length + river_width; i++) {
			create_water_tile(data, width, height, i, j, std::max((2 + river_width) * 2,7));
		}
	}
}
}
void env_humidity::generate_humidity(sprite_params** data, int width, int height) {
	//river asssociated generation

	int river_top_start  = 1 + (std::rand() % (width - 1));  //beginnig point of a river
	int river_width = rand() % (std::min(height, width) / 20);  //additional width of a river (actual river width = river_width + 1)
	int river_turn = (height / 10) + (std::rand() % (height - (height / 10)));	//Y axis (height) index of the turn of the river
	generate_river(data, width, height, river_top_start, 0, river_width,river_turn);


	//desert associated generation
	int desert_width = 3 + (rand() % ((width * 2 / 3)));	//width of the desert
	int desert_height = 3 + (rand() % ((height * 2 / 3)));	//heigth of the desert
	int desert_coordX = rand() % (width - desert_width - 1);	// X axis (width) index of the beginnig of desert
	int desert_coordY = rand() % (height - desert_height - 1);	// Y axis (height) index of the beginnig of desert
	generate_desert(data, desert_width, desert_height, desert_coordX, desert_coordY);


	//lake associated generation
	int lake_number = 1 + (rand() % (std::max(width, height) / 20));	//number of generated lakes
	while (lake_number > 0) {
		int lake_radius = 1 + (rand() % (std::min(width, height) / 10));	//radius of the lake 
		int lake_center_coordX = rand() % width;		// X axis (width) index of the middle point of lake
		int lake_center_coordY = rand() % height;	// Y axis (height) index of the middle point of lake
		generate_lake(data,width,height, lake_center_coordX, lake_center_coordY, lake_radius);
		lake_number--;
	}
	

	//Debug printing all humidity values
	/*
	for (int j = 0; j <= height; j++) {
		std::cout << "RZ¥D: " << j << std::endl;
		for (int i = 0; i <= width; i++) {
			std::cout << data[i][j].getHumidity() << "  ";
		}
		std::cout << std::endl;
	}
	*/
	
}
