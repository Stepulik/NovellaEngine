#include <iostream>
#include <vector>
#include <fstream>
#include <SFML/Graphics.hpp>

#include "person.cpp"

using namespace sf;


// Принцип сцены: одна картинка, набор диалогов(персонаж + слова персонажа), 

class Scene {
public:
	Scene(Texture* texture) {
		this->sceneTexture = texture;
		sceneSprite.setTexture(*texture);
	}

	Scene(const Scene& scene) {
		this->sceneTexture = scene.sceneTexture;
		sceneSprite.setTexture(*scene.sceneTexture);
		currentAction = scene.currentAction;
	}

	Scene& operator= (const Scene& scene) {
		this->sceneTexture = scene.sceneTexture;
		sceneSprite.setTexture(*scene.sceneTexture);
		currentAction = scene.currentAction;
		return *this;
	}


	~Scene() {}

	Sprite& getSceneSprite() {
		return sceneSprite;
	}

	Texture& getSceneTexture() {
		return *sceneTexture;
	}

	void addPhrase(Person* character, const wchar_t* text, int spriteNum) {
		textFont = new Font;
		textFont->loadFromFile("../media/fonts/m_Brody Regular.ttf");

		Text txt(text, *textFont, 40);
		txt.setFillColor(sf::Color::White);
		Phrase* phrase = new Phrase(character, txt, textFont, spriteNum);
		dialogList.push_back(phrase);
		currentAction = 0;
		
	}

	Text& getCurrentText() {
		if (currentAction != -1)
			return dialogList[currentAction]->text;
	}

	Color getCurrentColor() {
		if (currentAction != -1)
			return dialogList[currentAction]->character->getColor();
	}

	Text& getCurrentName() {
		if (currentAction != -1)
			return dialogList[currentAction]->name;
	}

	Sprite& getCurrentSprite() {
		if (currentAction != -1)
			return dialogList[currentAction]->spr;
	}

	
	bool nextPhrase() {
		if (currentAction != -1 && currentAction < dialogList.size() - 1) {
			currentAction++;
			return true;
		}
		else {
			return false;
		}
	}


private:
	Texture* sceneTexture = nullptr;
	Sprite sceneSprite;

	struct Phrase {
		Person* character = nullptr;
		Text text;
		Text name;
		Sprite spr;
		Phrase(Person* character, Text text, Font* font, int spriteNum) : character(character), text(text) {
			std::wstring widestr = std::wstring(character->getName().begin(), character->getName().end());
			name = Text(widestr, *font, 70); 
			name.setFillColor(character->getColor());
			spr = character->getSprite(spriteNum);
		}
	};
	
	//для каждой сцены будут храниться фразы: фраза - есть фиксированный задний фон 
	Font* textFont;
	int currentAction = 0;

	std::vector<Phrase*> dialogList;
};
