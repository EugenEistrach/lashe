#pragma once

#include <LashE/IGame.h>
#include "Player.h"

class Game : public lshe::IGame
{
public:
	Game();
	virtual ~Game();
protected:
	void update(sf::Time delta) override;
	void draw() override;

	void processEvents() override;
private:
	Player m_player;
};

