#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "Animal_core.h"

void Animals_gen::set_new(Animal _animal) {
	Animals_all.push_back(_animal);
}

std::vector< sf::Sprite >  Animals_gen::generate_animals()
{
	std::vector<sf::Sprite> sprites (Animals_all.size());
	for (int i = 0; i < Animals_all.size(); i++)
	{
		sprites[i].setTexture(texture);
		sprites[i].setPosition(sf::Vector2f(Animals_all[i].get_x()*32, Animals_all[i].get_y()*32));
		std::cout << sprites[i].getPosition().x << "\n";
	}
	return sprites;
	
}


int Animals_gen::get_amount() {
	return Animals_all.size();
}

void Animals_gen::remove_animal(int _index) {
	Animals_all.erase(Animals_all.begin() + _index);
	Animals_all.shrink_to_fit();
}

Animal Animals_gen::get_animal(int _index) {
	return Animals_all[_index];
}
Animals_gen::Animals_gen(sf::Texture _texture) {
	texture = _texture;
}

Animals_gen::~Animals_gen() {
	Animals_all.clear();
	Animals_all.shrink_to_fit();
}

sf::Texture Animals_gen::get_texture() {
	return texture;
}

std::vector<Animals_gen>  prepare_animals() {

	std::vector<Animals_gen> Animals;

	//Animal Texture
	sf::Texture cat_texture;
	if (!cat_texture.loadFromFile("textures/Cat.png"))
		std::cout << "Error isnt loaded!" << std::endl;
	else  std::cout << "properly loaded cat" << std::endl;

	sf::Texture camel_texture;
	if (!camel_texture.loadFromFile("textures/Camel.png"))
		std::cout << "Error isnt loaded!" << std::endl;
	else std::cout << "properly loaded camel" << std::endl;

	sf::Texture cow_texture;
	if (!cow_texture.loadFromFile("textures/Cow.png"))
		std::cout << "Error isnt loaded!" << std::endl;
	else std::cout << "properly loaded cow" << std::endl;

	sf::Texture bird_texture;
	if (!bird_texture.loadFromFile("textures/Bird.png"))
		std::cout << "Error isnt loaded!" << std::endl;
	else std::cout << "properly loaded bird" << std::endl;

	sf::Texture wolf_texture;
	if (!wolf_texture.loadFromFile("textures/Wolf.png"))
		std::cout << "Error isnt loaded!" << std::endl;
	else std::cout << "properly loaded wolf" << std::endl;

	sf::Texture fish_texture;
	if (!fish_texture.loadFromFile("textures/Fish.png"))
		std::cout << "Error isnt loaded!" << std::endl;
	else std::cout << "properly loaded fish" << std::endl;

	//generating animals
	Animals_gen Cats(cat_texture);
	Animals_gen Camels(camel_texture);
	Animals_gen Cows(cow_texture);
	Animals_gen Birds(bird_texture);
	Animals_gen Wolves(wolf_texture);
	Animals_gen Fishes(fish_texture);
	for (int i = 0; i < 4; i++)
	{
		Cat temp_anim(rand() % 30, rand() % 30, rand() % 2); //Creating cat with semiradnom parameters and putting in Cats array
		Cats.set_new(temp_anim);

	}
	Animals.push_back(Cats);
	for (int i = 0; i < 4; i++)
	{
		Camel temp_anim(rand() % 30, rand() % 30, rand() % 2); //Creating camel with semirandom parameters and putting in Camels array
		Camels.set_new(temp_anim);
	}
	Animals.push_back(Camels);


	return Animals;
}