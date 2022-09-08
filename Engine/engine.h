#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


#include "script.cpp"

using namespace sf;




class Engine {
public:
	Engine() : textureContainer(new std::map<std::string, Texture*>), sceneContainer(new std::map<std::string, Scene*>) {
		// ������, �������, ����������, �������� ������� ����� ����������
		// �������� ���������� ������, ������� ���� SFML � View
		Vector2f resolution;
		resolution.x = VideoMode::getDesktopMode().width;
		resolution.y = VideoMode::getDesktopMode().height;
		window.create(VideoMode(resolution.x, resolution.y),"Stepan in shkola", sf::Style::Fullscreen);
		
		//������ ������ ����������
		icon.loadFromFile("../media/textures/interface/icon.png");
		window.setIcon(128, 128, icon.getPixelsPtr());

		//��������� ���������������� �����
		menuFont.loadFromFile("../media/fonts/BitterPro-Black.ttf");
		textFont.loadFromFile("../media/fonts/NAMU-1990.ttf");

		//����� ��������� ��������, ��� ��� ���� ��������� �� � �� ����� ��� ����� ��������
		loadTextures(texturePathes);

		//script.start();
		script.setTextureContainer(textureContainer);
		script.setSceneContainer(sceneContainer);
		script.setFont(menuFont, textFont);
		script.setTextSize(menuButtonSize, textSize);
		script.startAddScenes();
	}

	~Engine() {
	}

	void Game(int& currentLevel, std::pair<int, int>& blockIndex);

private:
	Script script;

	RenderWindow window;

	std::string mediaPath = "../media";
	std::string charactersPath = "/characters/";
	std::vector<std::string> texturePathes;
	std::map<std::string, Texture*>* textureContainer;
	std::map<std::string, Scene*>* sceneContainer;

	Image icon;

	Texture cursorTexture;
	Sprite cursor;

	int menuButtonSize = 16;
	Font menuFont;

	int textSize = 20;
	Font textFont;
	

	const Color defaultButtonColor = Color::White;
	const Color changeButtonColor = Color::Red;

	const Color defaultScrollbarColor = Color(113, 113, 113);
	const Color changedScrollbarColor = Color::Yellow;

	Texture* getTexture(std::string key) {
		return (*textureContainer)[key];
	}

	//std::map<std::string, Scene> sceneContainer;

	//������� ����
	int mainMenu(RenderWindow& window);

	//�����
	int titles(RenderWindow& window);

	//�������� ������� �����(���� ����)
	int gameWindow(RenderWindow& window, std::pair<int, int>& blockIndex);

	//��������������� �������� �������
	void loadTextures(std::vector<std::string>& texturePathes);

	//��������� ��������� �� ������ � ������������ ��������
	bool isContainMouse(RenderWindow& window, int x, int y, int posX, int posY); 
};