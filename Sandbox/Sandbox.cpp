// Sandbox.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//
#include "stdafx.h"
#include <iostream>


#include "Game.h"
#include "Configuration.h"

int main()
{
	Configuration::initialize();

	Game game;
	game.run(60);

	return 0;
}

