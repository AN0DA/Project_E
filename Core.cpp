#include "Core.h"
#include <cstdlib>
#include <iostream>
bool mustgenthisforfucksake = true;
int Core::GenerateRandomInt(int a) {
	if (mustgenthisforfucksake)
	{
	srand((unsigned)time(NULL));
	mustgenthisforfucksake = false;
	}
	std::cout << " wygenerowano losowa liczbe: "<< rand() % 10 + 1;

	return rand() % a + 1;
}