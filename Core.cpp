#include "Core.h"
#include <cstdlib>
#include <iostream>
int Core::GenerateRandomInt(int a) { 
	srand((unsigned)time(NULL));
	std::cout << " wygenerowano losowa liczbe: "<< rand() % 10 + 1;

	return rand() % a + 1;
}