#include "IGame.h"
#include "ActionTarget.h"

namespace lshe
{

	IGame::IGame(const std::string& windowName, unsigned int width, unsigned int height) : m_window(sf::VideoMode(width, height), windowName)
	{
	}

	void IGame::run(int fps)
	{
		init();
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
				m_sceneManager.update(TIME_PER_FRAME);
			}
			m_sceneManager.update(timeSinceLastUpdate);
			render();
		}
	}

	void IGame::processEvents()
	{
		sf::Event evt;
		while(m_window.pollEvent(evt))
		{
			switch (evt.type)
			{
			case sf::Event::Closed:
				m_window.close();
				break;
			case sf::Event::KeyPressed:
				if (evt.key.code == sf::Keyboard::Escape)
					m_window.close();
				break;
			default: break;
			}
			m_sceneManager.processEvent(evt);
		}
		m_sceneManager.processEvents();
	}

	void IGame::render()
	{
		m_window.clear();
		m_window.draw(m_sceneManager.getCurrentScene());
		m_window.display();
	}
}
