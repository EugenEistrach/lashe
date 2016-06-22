#pragma once

#include <SFML/Graphics.hpp>
#include "SceneManager.h"

namespace lshe
{
	class IGame
	{
	public:
		IGame(const IGame&) = delete;
		IGame& operator=(const IGame&) = delete;
		IGame() = delete;
		IGame(const std::string& windowName, unsigned int width, unsigned int height);



		void run(int fps = 60);
		SceneManager& getSceneManager() { return m_sceneManager; }

	private:
		void gameLoop(int fps);
		void processEvents();
		void render();
		
	protected:
		virtual void init() = 0;


		sf::RenderWindow m_window;
		SceneManager m_sceneManager;
	};
}



