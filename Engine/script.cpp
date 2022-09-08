#include <iostream>
#include <list>
#include <algorithm>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "block.cpp" 
using namespace sf;

class Script {
public:

	Script(){}

	void startAddScenes() {
		persons = new std::map<std::string, Person*>;

		// ��������� ����������
		addPerson("Stepan", 9, Color::Yellow);
		addPerson("Julia", 3, Color::Green);
		addPerson("Karina", 3, Color::Cyan);
		

		// ������������� �����
		addScene("start1");
		getScene("start1").addPhrase(getPerson("Stepan"), L"����... � ����� �������, ���� ������.", 2);

		addScene("start2");
		getScene("start2").addPhrase(getPerson("Stepan"), L"->", 0);
		
		addScene("start3");
		getScene("start3").addPhrase(getPerson("Julia"), L"-������.����� �����������?", 1);
		getScene("start3").addPhrase(getPerson("Stepan"), L"��-��...", 0);
		getScene("start3").addPhrase(getPerson("Julia"), L"�����, ������. �� ����� ����� �����?", 0);
		getScene("start3").addPhrase(getPerson("Julia"), L"s", 1);
		getScene("start3").addPhrase(getPerson("Karina"), L"������������, � ��� ��������?", 1);
		getScene("start3").addPhrase(getPerson("Julia"), L"�� �����, � ��� ��� ���� �������.", 2);
		getScene("start3").addPhrase(getPerson("Karina"), L"���, �� ����� �����������... ������, �� �� ����� � ����������, ��?", 1);
		getScene("start3").addPhrase(getPerson("Karina"), L"������������� �� ���� ����� �����? �������� �� ����.", 0);
		getScene("start3").addPhrase(getPerson("Julia"), L"������, �� �� �������� ��� ������������ ����� ������� � ����. ����� ��, ������.", 2);
		getScene("start3").addPhrase(getPerson("Karina"), L"��� ������?", 2);
		getScene("start3").addPhrase(getPerson("Stepan"), L"||", 0);

		// ��������� ����� � ����
		blockContainer.push_back(new Block);
		blockContainer[0]->addScene(&getScene("start1"));
		blockContainer[0]->addScene(&getScene("start2"));
		blockContainer[0]->addScene(&getScene("start3"));
		blockContainer[0]->addChoise(L"������ � �������", L"����� � ����");

		// ����� 1
		addScene("choise1_1i1");
		getScene("choise1_1i1").addPhrase(getPerson("Stepan"), L"������, ������, � ������ ���� � ����������� � ��������.", 0);

		addScene("choise1_1i2");
		getScene("choise1_1i2").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_1i2").addPhrase(getPerson("Karina"), L"���...��� ����...� ���...", 0);
		getScene("choise1_1i2").addPhrase(getPerson("Stepan"), L"������!", 1);
		getScene("choise1_1i2").addPhrase(getPerson("Stepan"), L"", 0);
		getScene("choise1_1i2").addPhrase(getPerson("Stepan"), L"�������, ������, � ���� �������� ����������!", 1);
		getScene("choise1_1i2").addPhrase(getPerson("Karina"), L"s", 1);

		addScene("choise1_1i3");
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"��, ��� ��� ������, ��� ���� ����.", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"����� ����������?", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"�� �����.", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"�� ��� ��� �����, ����� � ���� �� ���� �������?", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"� ���� �� ������ ����, �� ���� �� ����� �������� ���...", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"�� ������ ����� � ������ ������� ����� � �����, � �� � ���?)", 1);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"�� ����, ����� ������ ��� �� ����� ������ � ������ ������� ��� ������...", 2);
		getScene("choise1_1i3").addPhrase(getPerson("Stepan"), L"���, �� ��� ����� ���������, ������� � � ������� � ����.", 0);
		getScene("choise1_1i3").addPhrase(getPerson("Karina"), L"�� ��� ���� ����� ���������, �� � ����� ������� ���� ����������, � ��� ����...", 1);

		addScene("choise1_1i4");
		getScene("choise1_1i4").addPhrase(getPerson("Stepan"), L"", 0);
		getScene("choise1_1i4").addPhrase(getPerson("Stepan"), L"end", 0);

		blockContainer.push_back(new Block);
		blockContainer[1]->addScene(&getScene("choise1_1i1"));
		blockContainer[1]->addScene(&getScene("choise1_1i2"));
		blockContainer[1]->addScene(&getScene("choise1_1i3"));
		blockContainer[1]->addScene(&getScene("choise1_1i4"));


		// 2 �����
		addScene("choise1_2i1");
		getScene("choise1_2i1").addPhrase(getPerson("Stepan"), L"��� ������, �� � ���� ��� ������������ ����� ������.", 0);
		getScene("choise1_2i1").addPhrase(getPerson("Karina"), L"�� ������� ��� ������!", 2);
		getScene("choise1_2i1").addPhrase(getPerson("Stepan"), L"������.", 0);

		addScene("choise1_2i2");
		getScene("choise1_2i2").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_2i2").addPhrase(getPerson("Julia"), L"������, ��� ��� �������, � ����� ��� �� �������� � ����������� ��-�����...", 1);
		getScene("choise1_2i2").addPhrase(getPerson("Stepan"), L"��, � �������, � �������� �� �� �����...", 1);
		
		addScene("choise1_2i3");
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"�� ��! � ��� ��� ���?", 1);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"���?", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"������!", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"���� ������� ��������, ������?", 1);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"->", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"������...", 1);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"��� �������� ������, ����� ���� ���� �� �����?", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"�����!", 2);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"����� ������� ��� �������.", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Julia"), L"��� ��� ��� ��������.", 0);
		getScene("choise1_2i3").addPhrase(getPerson("Stepan"), L"�����...", 0);

		addScene("choise1_2i4");
		getScene("choise1_2i4").addPhrase(getPerson("Stepan"), L"", 0);
		getScene("choise1_2i4").addPhrase(getPerson("Stepan"), L"end", 0);

		blockContainer.push_back(new Block);
		blockContainer[2]->addScene(&getScene("choise1_2i1"));
		blockContainer[2]->addScene(&getScene("choise1_2i2"));
		blockContainer[2]->addScene(&getScene("choise1_2i3"));
		blockContainer[2]->addScene(&getScene("choise1_2i4"));

	}

	~Script() {}

	void addScene(std::string key) {
		Scene* scene = new Scene((*textureContainer)["/galery/" + key + ".jpg"]);
		sceneContainer->insert(std::make_pair("/galery/" + key + ".jpg", scene));
	}

	Scene& getScene(std::string key) {
		return *(*sceneContainer)["/galery/" + key + ".jpg"]; // key
	}

	Block& getBlock(int key) {
		return *blockContainer[key]; // key
	}

	void addPerson(std::string name, int spritesNum, Color color = Color::White) {
		Person* person = new Person(name, spritesNum, color);
		persons->insert(std::make_pair(name, person));
	}

	Person* getPerson(std::string key) {
		return (*persons)[key];
	}


	void setTextureContainer(std::map<std::string, Texture*>* textureContainer) {
		this->textureContainer = textureContainer;
	}

	void setSceneContainer(std::map<std::string, Scene*>* sceneContainer) {
		this->sceneContainer = sceneContainer;
	}

	void setFont(Font menuFont, Font textFont) {
		this->menuFont = menuFont;
		this->textFont = textFont;
	}

	void setTextSize(int menuButtonSize, int textSize) {
		this->menuTextSize = menuButtonSize;
		this->textSize = textSize;
	}



private:
	std::map<std::string, Texture*>* textureContainer = nullptr;

	std::map<std::string, Scene*>* sceneContainer = nullptr;
	std::vector<std::string> keys;
	
	std::map<std::string, Person*>* persons = nullptr;

	std::vector<Block*> blockContainer;

	Font menuFont;
	int menuTextSize;

	Font textFont;
	int textSize;
};