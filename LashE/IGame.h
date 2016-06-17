#pragma once

#include <SFML/Graphics.hpp>

namespace lshe
{
	class IGame
	{
	public:
		IGame(const IGame&) = delete;
		IGame& operator=(const IGame&) = delete;
		IGame();

		void run(int fps = 60);

	private:
		void gameLoop(int fps);
		
		void render();
		
	protected:
		virtual void processEvents();
		virtual void update(sf::Time delta) = 0;
		virtual void draw() = 0;

		sf::RenderWindow m_window;
	};
}



