#include "engine.h"


void Engine::Game(int& currentLevel, std::pair<int, int>& blockIndex) {
	//При заходе вызываем главное меню и работаем с ним
	switch (currentLevel) {
	case -1:
		currentLevel = mainMenu(window);
		break;
	case -3:
		return;
		break;
	case 1:
		currentLevel = gameWindow(window, blockIndex);
		break;
	case 2:
		currentLevel = titles(window);
		break;
	}
	if(currentLevel != 0)
		Game(currentLevel, blockIndex);
}


int Engine::mainMenu(RenderWindow& window) {
	//предполагается, что все кнопки одинакового размера
	const int buttonSize = 100;
	Text menuButton1(L"Новая игра", menuFont, buttonSize), menuButton2(L"Титры", menuFont, buttonSize), menuButton3(L"Выход", menuFont, buttonSize);


	bool isMainMenu = true;
	int clickedButton = 0;
	bool isClicked = false;

	const int posX = 700;
	const int posY = 300;
	const int spaceX = 600;
	const int spaceY = 30;
	const int buttonHeight = menuButton1.getGlobalBounds().height;


	menuButton1.setPosition(posX, posY);
	menuButton2.setPosition(posX, posY + (spaceY + buttonHeight));
	menuButton3.setPosition(posX, posY + (spaceY + buttonHeight) * 2);

	SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("../media/sounds/menubutton.wav");
	Sound click(clickBuffer);

	Music menuTheme;
	menuTheme.openFromFile("../media/music/music1.wav");
	menuTheme.setLoop(true);
	menuTheme.play();

	bool isFocus = true;

	while (isMainMenu) {
		menuButton1.setFillColor(defaultButtonColor);
		menuButton2.setFillColor(defaultButtonColor);
		menuButton3.setFillColor(defaultButtonColor);
		window.clear(Color(222, 100, 21));

		//setCursorPos(window);

		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed) {
				window.close();
				isMainMenu = false;
			}

			//окно открыто или свернуто
			if (event.type == sf::Event::LostFocus)
				isFocus = false;

			if (event.type == sf::Event::GainedFocus)
				isFocus = true;
			if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				if (isFocus) {
					if (isContainMouse(window, posX, posY, menuButton1.getGlobalBounds().width, buttonHeight * 1.3)) {
						clickedButton = 1;
					}
					if (isContainMouse(window, posX, posY + (spaceY + buttonHeight), menuButton2.getGlobalBounds().width, buttonHeight * 1.3)) {
						clickedButton = 2;
					}
					if (isContainMouse(window, posX, posY + (spaceY + buttonHeight) * 2, menuButton3.getGlobalBounds().width, buttonHeight * 1.3)) {
						clickedButton = -3;
					}
					if (clickedButton != 0) {
						click.play();
						isClicked = true;
					}
				}
			}
		}

		//если текущим выбранным является это окно, то даем возможность пользоваться кнопками(иначе анархия)
		if (isFocus) {
			//если наводимся на одну из кнопок то меняем цвет кнопки
			if (isContainMouse(window, posX, posY, menuButton1.getGlobalBounds().width, buttonHeight * 1.3)) {
				menuButton1.setFillColor(changeButtonColor);
			}
			if (isContainMouse(window, posX, posY + (spaceY + buttonHeight), menuButton2.getGlobalBounds().width, buttonHeight * 1.3)) {
				menuButton2.setFillColor(changeButtonColor);
			}
			if (isContainMouse(window, posX, posY + (spaceY + buttonHeight) * 2, menuButton3.getGlobalBounds().width, buttonHeight * 1.3)) {
				menuButton3.setFillColor(changeButtonColor);
			}
		}


		if (isClicked && !click.getStatus()) {
			isMainMenu = false;
		}


		Sprite menuBg;
		menuBg.setTexture(*getTexture("/textures/mainmenu/mainmenubackground.jpg"));
		window.draw(menuBg);
		window.draw(menuButton1);
		window.draw(menuButton2);
		window.draw(menuButton3);

		window.display();
	}
	menuTheme.stop();
	return clickedButton;
}

int Engine::gameWindow(RenderWindow& window, std::pair<int, int>& blockIndex) {
	Music gameTheme;
	gameTheme.openFromFile("../media/music/gamemusic.wav");
	gameTheme.setLoop(true);
	gameTheme.play();

	SoundBuffer clickBuffer;
	clickBuffer.loadFromFile("../media/sounds/nextscenebutton.wav");
	Sound click(clickBuffer);

	bool isGameWindow = true;
	bool isFocus = true;

	int clickedChoise = 0;

	int res = -1;
	bool isChoise = false;

	while (isGameWindow) {
		bool isClicked = false;


		Sprite textTable;
		textTable.setTexture(*getTexture("/textures/interface/texttable.png"));
		textTable.setScale(1, 0.75f);
		textTable.setPosition(150, 700);

		Sprite rightArrow;
		rightArrow.setTexture(*getTexture("/textures/interface/arrow.png"));
		rightArrow.setPosition(1760, 950);

		if (isContainMouse(window, 1760, 950, rightArrow.getGlobalBounds().width, rightArrow.getGlobalBounds().height)) {
			rightArrow.setColor(Color::Green);
		}



		script.getBlock(blockIndex.first).getChoise1Text().setPosition(VideoMode::getDesktopMode().width / 2 - 200, VideoMode::getDesktopMode().height / 3);
		script.getBlock(blockIndex.first).getChoise2Text().setPosition(VideoMode::getDesktopMode().width / 2 - 200, VideoMode::getDesktopMode().height / 2);
		script.getBlock(blockIndex.first).getChoise1Text().setFillColor(Color::White);
		script.getBlock(blockIndex.first).getChoise2Text().setFillColor(Color::White);

		window.clear();

		//setCursorPos(window); //потенциал для своего курсора, но в процессе оказалось, что мысль не очень

		Event event;

		while (window.pollEvent(event) && !isClicked)
		{
			//окно открыто или свернуто
			if (event.type == sf::Event::LostFocus)
				isFocus = false;

			if (event.type == sf::Event::GainedFocus)
				isFocus = true;


			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed) {
				res = -3;
				window.close();

				isGameWindow = false;
			}
			if (event.type == sf::Event::KeyPressed)
			{
				if (event.key.code == sf::Keyboard::Escape)
				{
					res = -2;
				}
			}
			else if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left)
			{
				if (isFocus) {
					click.play();
					if (isChoise) {
						if (isContainMouse(window, VideoMode::getDesktopMode().width / 2 - 200, VideoMode::getDesktopMode().height / 3,
							script.getBlock(blockIndex.first).getChoise1Text().getGlobalBounds().width,
							script.getBlock(blockIndex.first).getChoise1Text().getGlobalBounds().height * 1.3)) {

							clickedChoise = 1;
						}
						else if (isContainMouse(window, VideoMode::getDesktopMode().width / 2 - 200, VideoMode::getDesktopMode().height / 2,
							script.getBlock(blockIndex.first).getChoise2Text().getGlobalBounds().width,
							script.getBlock(blockIndex.first).getChoise2Text().getGlobalBounds().height * 1.3)) {

							clickedChoise = 2;
						}
					}

					if (isContainMouse(window, 1760, 950, rightArrow.getGlobalBounds().width, rightArrow.getGlobalBounds().height)) {
						isClicked = true;
					}
					if (isClicked || clickedChoise) { // если кликнули -> идем дальше
						if (script.getBlock(blockIndex.first).getCurrentScene().nextPhrase()) {

						}
						else if (script.getBlock(blockIndex.first).nextScene()) {

						}
						else if (blockIndex.first + 2 < blockIndex.second) {
							if (clickedChoise == 1) {
								blockIndex.first++;
							}
							else if (clickedChoise == 2) {
								blockIndex.first += 2;
							}
							clickedChoise = 0;
							isClicked = false;
							isChoise = false;
						}
						else {
							isGameWindow = false;
						}
					}
				}
			}
		}

		window.draw(script.getBlock(blockIndex.first).getCurrentScene().getSceneSprite());
		script.getBlock(blockIndex.first).getCurrentScene().getCurrentSprite().setScale(0.4, 0.4);
		script.getBlock(blockIndex.first).getCurrentScene().getCurrentSprite().setPosition(VideoMode::getDesktopMode().width / 2 - 300, VideoMode::getDesktopMode().height / 3 - 100);

		// было принято решение, что пустая строка обозначает отсутствие интерфейса, для атмосферы
		if (script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().getString().toWideString() == L"||") {
			isChoise = true;
			if (isContainMouse(window, VideoMode::getDesktopMode().width / 2 - 200, VideoMode::getDesktopMode().height / 3,
				script.getBlock(blockIndex.first).getChoise1Text().getGlobalBounds().width,
				script.getBlock(blockIndex.first).getChoise1Text().getGlobalBounds().height * 1.3)) {

				script.getBlock(blockIndex.first).getChoise1Text().setFillColor(Color::Yellow);
			}
			if (isContainMouse(window, VideoMode::getDesktopMode().width / 2 - 200, VideoMode::getDesktopMode().height / 2,
				script.getBlock(blockIndex.first).getChoise2Text().getGlobalBounds().width,
				script.getBlock(blockIndex.first).getChoise2Text().getGlobalBounds().height * 1.3)) {

				script.getBlock(blockIndex.first).getChoise2Text().setFillColor(Color::Yellow);
			}
		}

		if (script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().getString().toWideString() != L""
			&& script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().getString().toWideString() != L"->"
			&& script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().getString().toWideString() != L"s"
			&& script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().getString().toWideString() != L"end"
			&& !isChoise) {
			window.draw(script.getBlock(blockIndex.first).getCurrentScene().getCurrentSprite());
			window.draw(textTable);
			window.draw(rightArrow);

			script.getBlock(blockIndex.first).getCurrentScene().getCurrentName().setPosition(295, 700);
			script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().setPosition(200, 785);

			window.draw(script.getBlock(blockIndex.first).getCurrentScene().getCurrentName());
			window.draw(script.getBlock(blockIndex.first).getCurrentScene().getCurrentText());
		}
		else if (script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().getString().toWideString() == L"->") {
			window.draw(rightArrow);
		}
		else if (script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().getString().toWideString() == L"||") {
			window.draw(script.getBlock(blockIndex.first).getCurrentScene().getCurrentSprite());
			window.draw(script.getBlock(blockIndex.first).getChoise1Text());
			window.draw(script.getBlock(blockIndex.first).getChoise2Text());
		}
		else if (script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().getString().toWideString() == L"s") {
			window.draw(script.getBlock(blockIndex.first).getCurrentScene().getCurrentSprite());
			window.draw(rightArrow);
		}
		else if (script.getBlock(blockIndex.first).getCurrentScene().getCurrentText().getString().toWideString() == L"end") {
			return 2;
		}

		window.display();

	}
	gameTheme.stop();
	return res;
}

int Engine::titles(RenderWindow& window) {
	bool isTitles = true;
	int clickedButton = 0;
	bool isClicked = false;

	bool isFocus = true;

	while (isTitles) {
		window.clear();

		Event event;
		while (window.pollEvent(event))
		{
			// Пользователь нажал на «крестик» и хочет закрыть окно?
			if (event.type == Event::Closed) {
				window.close();
				isTitles = false;
			}

			//окно открыто или свернуто
			if (event.type == sf::Event::LostFocus)
				isFocus = false;

			if (event.type == sf::Event::GainedFocus)
				isFocus = true;
		}

		//если текущим выбранным является это окно, то даем возможность пользоваться кнопками(иначе анархия)
		if (isFocus) {
			if (Mouse::isButtonPressed(Mouse::Left))
			{
				isTitles = false;
				clickedButton = -1;
			}
		}
		
		Sprite titlesBg;
		titlesBg.setTexture(*getTexture("/textures/mainmenu/titles.jpg"));
		window.draw(titlesBg);
		window.display();
	}
	return clickedButton;
}

void Engine::loadTextures(std::vector<std::string> &texturePathes) {
	//текстуры главного меню
	texturePathes.push_back("/textures/mainmenu/mainmenubackground.jpg");
	texturePathes.push_back("/textures/mainmenu/titles.jpg");



	//текстуры для сцен
	texturePathes.push_back("/textures/interface/texttable.png");
	texturePathes.push_back("/textures/interface/arrow.png");
	texturePathes.push_back("/galery/start1.jpg");
	texturePathes.push_back("/galery/start2.jpg");
	texturePathes.push_back("/galery/start3.jpg");
	texturePathes.push_back("/galery/choise1_1i1.jpg");
	texturePathes.push_back("/galery/choise1_1i2.jpg");
	texturePathes.push_back("/galery/choise1_1i3.jpg");
	texturePathes.push_back("/galery/choise1_1i4.jpg");
	texturePathes.push_back("/galery/choise1_2i1.jpg");
	texturePathes.push_back("/galery/choise1_2i2.jpg");
	texturePathes.push_back("/galery/choise1_2i3.jpg");
	texturePathes.push_back("/galery/choise1_2i4.jpg");
	

	for (std::string path : texturePathes) {
		Texture* texture = new Texture;
		texture->loadFromFile(mediaPath + path);
		textureContainer->insert(std::make_pair(path, texture));
	}
	
}

bool Engine::isContainMouse(RenderWindow& window, int x, int y, int posX, int posY) {
	return IntRect(x, y, posX, posY).contains(Mouse::getPosition(window));
}