// Sandbox.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"

#include <iostream>


#include "Game.h"
#include "Player.h"
#include "Configuration.h"

enum States : unsigned long long {
	UP, DOWN, LEFT, RIGHT
};


int main()
{
	Configuration::initialize();

	std::cout << sizeof(States) / sizeof(States::DOWN);

	Game game;
	game.run();

	return 0;
}

