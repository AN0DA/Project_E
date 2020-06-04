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
		std::cout << sprites[i].getTexture() << "\n";
		std::cout << Animals_all[i].get_type() << "\n";


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