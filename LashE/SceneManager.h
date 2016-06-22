#pragma once

#include <memory>
#include <SFML/System/Time.hpp>

#include "IGameScene.h"


namespace lshe 
{
	class SceneManager
	{
	public:
		SceneManager() = default;
		SceneManager(const SceneManager&) = delete;
		SceneManager& operator=(const SceneManager&) = delete;
		~SceneManager() { m_curScene->unload(); }
		
		void update(sf::Time deltaTime) { m_curScene->updateEntityWorld(); m_curScene->update(deltaTime); };
		//void draw() { m_curScene->draw(); };
		void processEvent(const sf::Event& evt) { m_curScene->processEvent(evt); }
		void processEvents() { m_curScene->processEvents(); }

		template<typename T>
		void call()
		{
			if (m_curScene.get())
				m_curScene->unload();
			m_curScene = std::make_unique<T>();
			m_curScene->load();
		}

		IGameScene& getCurrentScene() const { return *m_curScene.get(); }

	private:
		std::unique_ptr<IGameScene> m_curScene;
	};

}


