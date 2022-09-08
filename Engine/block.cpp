#include "scene.cpp"

class Block {
public:
	Block() {}

	Scene& getCurrentScene() {
		return *scenes[currentScene];
	}

	void addScene(Scene* scene) {
		scenes.push_back(scene);
	}

	bool nextScene() {
		if (currentScene < scenes.size() - 1) {
			currentScene++;
			return true;
		}
		else
			return false;
	}

	bool nextScene(int num) {
		if (currentScene + num < scenes.size() - 1) {
			currentScene += num;
			return true;
		}
		else
			return false;
	}

	void addChoise(const wchar_t* choise1, const wchar_t* choise2) {
		textFont = new Font;
		textFont->loadFromFile("../media/fonts/m_Brody Regular.ttf");
		isChoise = true;
		choise.first = Text(choise1, *textFont, 100);
		choise.second = Text(choise2, *textFont, 100);
	}

	Text& getChoise1Text() {
		return choise.first;
	}

	Text& getChoise2Text() {
		return choise.second;
	}

private:
	std::vector<Scene*> scenes;
	int currentScene;

	Font* textFont;
	bool isChoise = false;
	std::pair<Text, Text> choise;
};