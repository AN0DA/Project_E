#pragma once
class env_temperature
{
	//TEMPORARY
	static const int temperature_min = 18;
	static const int temperature_max = 26.5;
	static const int biome = 1;

public:
	void generate_temperature(int biome = biome, int temperature_min = temperature_min, int temperature_max = temperature_max);
};

