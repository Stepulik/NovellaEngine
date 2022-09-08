#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Engine.h"

using namespace sf;


int main()
{
	//currentWindpow говорит игре какой тип окна сейчас
	int currentWindow = -1;

	// в индексах: первое число текущий индекс блока, 2 число всего блоков
	std::pair<int, int> blockIndex(0, 3); 

	Engine engine;
	engine.Game(currentWindow, blockIndex);

	return 0;
}