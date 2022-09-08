#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Engine.h"

using namespace sf;


int main()
{
	//currentWindpow ������� ���� ����� ��� ���� ������
	int currentWindow = -1;

	// � ��������: ������ ����� ������� ������ �����, 2 ����� ����� ������
	std::pair<int, int> blockIndex(0, 3); 

	Engine engine;
	engine.Game(currentWindow, blockIndex);

	return 0;
}