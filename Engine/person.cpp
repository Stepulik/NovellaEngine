#include <iostream>
#include <stdexcept>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;


// класс персон, он содержит спрайты, цевет имени и имя персонажа
class Person {
public:
	Person() {}
	Person(std::string name, int spritesNum, Color color = Color::White) {
		this->name = name;
		this->color = color;
		this->spritesNum = spritesNum;
		this->personTexture = new Texture[spritesNum];
		for (int i = 0; i < spritesNum; i++) {
			std::string path = "";
			path = std::string("../media/characters/") + name + std::string("/") + std::to_string(i) + std::string(".png");
			personTexture[i].loadFromFile(path);
		}
		this->spritesNum = spritesNum;
		sprites = new Sprite[spritesNum];
		for (int i = 0; i < spritesNum; i++) {
			Sprite spr;
			spr.setTexture(personTexture[i]);
			sprites[i] = std::move(spr);
		}
	}

	Person(const Person& person) {
		this->name = name;
		this->color = color;
		this->personTexture = person.personTexture;
		this->spritesNum = spritesNum;
		sprites = person.sprites;
	}

	Person& operator=(const Person& person) {
		this->name = name;
		this->color = color;
		this->personTexture = person.personTexture;
		this->spritesNum = spritesNum;
		sprites = person.sprites;

		return *this;
	}

	~Person() {
		delete[]personTexture;
		delete[] sprites;
	}

	Sprite& getSprite(int num) {
		if (num >= 0 && num < spritesNum)
			return sprites[num];
		else
			std::cout << "Incorrect sprite: " << name;
		return sprites[0];
	}

	Color& getColor() {
		return color;
	}

	std::string& getName() {
		return name;
	}

private:
	Sprite* sprites;
	std::string name;
	Color color;
	Texture* personTexture;
	int spritesNum;
};
// 0 - smile
// 1 - happy
// 2 - angry