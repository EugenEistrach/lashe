#include "IGame.h"
#include "ActionTarget.h"
#include <iostream>
#include <string>
namespace lshe
{

	IGame::IGame(const std::string& windowName, unsigned int width, unsigned int height) : m_window(sf::VideoMode(width, height), windowName)
	{
	}

	void IGame::run(int fps)
	{

		if (!m_fpsfont.loadFromFile("assets/fonts/arial.ttf"))
		{
			std::cout << "Font loading error" << std::endl;
		}

		m_fpsText.setFont(m_fpsfont);
		m_fpsText.setColor(sf::Color::Red);
		m_fpsText.setCharacterSize(32);
		init();
		gameLoop(fps);
	}

	void IGame::gameLoop(int fps)
	{
		sf::Clock clock;
		const sf::Time TIME_PER_FRAME = sf::seconds(1.0f / fps);

		float t = 0.0f;
		float currentTime = clock.restart().asSeconds();
		float accumulator = 0.0f;

		while(m_window.isOpen())
		{
			float frameTime = clock.restart().asSeconds();
			//float newTime = clock.restart().asSeconds();
			//float frameTime = newTime - currentTime;

			m_fps = 1.0f / frameTime;

			if (frameTime > 0.25f)
				frameTime = 0.25f;

			//currentTime = newTime;
			accumulator += frameTime;
			processEvents();

			while(accumulator >= TIME_PER_FRAME.asSeconds())
			{
				m_sceneManager.update(TIME_PER_FRAME);
				accumulator -= TIME_PER_FRAME.asSeconds();
				t += TIME_PER_FRAME.asSeconds();
			}


			const float alpha = accumulator / TIME_PER_FRAME.asSeconds();

			std::cout << alpha << std::endl;

			m_fpsText.setString(std::to_string(m_fps));
			render(alpha);
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

	void IGame::render(float alpha)
	{
		m_window.clear(sf::Color::Magenta);
		m_sceneManager.getCurrentScene().draw(m_window, alpha);
		m_window.draw(m_fpsText);
		m_window.display();
	}
}
