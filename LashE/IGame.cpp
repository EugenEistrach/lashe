#include "IGame.h"

namespace lshe
{

	IGame::IGame() : m_window(sf::VideoMode(800, 600), "LashE")
	{
	}

	void IGame::run(int fps)
	{
		gameLoop(fps);
	}

	void IGame::gameLoop(int fps)
	{
		sf::Clock clock;
		sf::Time timeSinceLastUpdate;
		const sf::Time TIME_PER_FRAME = sf::seconds(1.0f / fps);

		while(m_window.isOpen())
		{
			processEvents();

			timeSinceLastUpdate = clock.restart();

			while(timeSinceLastUpdate > TIME_PER_FRAME)
			{
				timeSinceLastUpdate -= TIME_PER_FRAME;
				update(TIME_PER_FRAME);
			}

			update(timeSinceLastUpdate);
			render();
		}
	}

	void IGame::processEvents()
	{
		sf::Event event;
		while(m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				if (event.key.code == sf::Keyboard::Escape)
					m_window.close();
				break;
			default: break;
			}
		}
	}

	void IGame::render()
	{
		m_window.clear();
		draw();
		m_window.display();
	}
}
