#include <cstdlib>
#include <iostream>
#include "Core.h"

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
int sprite_params::getX() {
	return this->x;
}
int sprite_params::getY() {
	return this->y;
}
int sprite_params::getHumidity() {
	return this->humidity;
}
void sprite_params::setHumidity(int newHumidity) {
	this->humidity = newHumidity;
}
bool sprite_params::getRootStatus() {
	return this->isRooted;
}
void sprite_params::setRootStatus(bool newStatus) {
	this->isRooted = newStatus;
}