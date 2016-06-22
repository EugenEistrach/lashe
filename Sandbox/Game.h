#pragma once

#include <LashE/IGame.h>

class Game : public lshe::IGame
{
public:
	Game() : IGame("Lash-E Sandbox", 1440, 900) {}
	virtual ~Game();

	// Geerbt über IGame
	virtual void init() override;
};

