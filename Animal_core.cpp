#include "Animal_core.h"

void Animals_gen::create_new(Animal _animal) {
	Animals_all.push_back(_animal);
}
void Animals_gen::generate_animals(sf::Window* window)
{
	//texture init for animals
	sf::Texture animal;
	if (!animal.loadFromFile(Animals_all[0].get_sprite()))
	{
		std::cout << "cat isnt loaded!";
	}

	//end of lodin
	sf::Sprite sprites[500][500];
	for (int i = 0; i < 500; i++)
	{
		for (int j = 0; j < 500; j++)
		{
			//sprite.setColor(sf::Color(rand, rand, rand));				TO DO!
			sprites[i][j].setTexture(animal);
			sprites[i][j].setPosition(sf::Vector2f(i, j));
			//window->setVisible();
			window->display();//draw(sprites[i][j]);
		}
	}
}