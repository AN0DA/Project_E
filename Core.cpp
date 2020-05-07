#include "Core.h"
#include <cstdlib>
#include <iostream>
bool mustgenthisforfucksake = true;
int Core::GenerateRandomInt(int a) {
	if (mustgenthisforfucksake)
	
	srand((unsigned)time(NULL));
	mustgenthisforfucksake = false;
	return rand() % a + 1;
	}

void  sprite_params::set_temperature(double _temperature) {
	temperature = _temperature;
}

double sprite_params::get_temperature() {
	return temperature;
}
sprite_params::sprite_params() {
	temperature = 0;
}