// Sandbox.cpp : Definiert den Einstiegspunkt f�r die Konsolenanwendung.
//

#include "stdafx.h"
#include "Game.h"
#include "Player.h"
#include "Configuration.h"

int main()
{
	Configuration::initialize();

	Game game;
	game.run();

	return 0;
}

