#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>

namespace lshe
{
	//class IGame;

	class IGameScene : public sf::Drawable
	{
	public:
		IGameScene(const IGameScene&) = delete;
		IGameScene& operator=(const IGameScene&) = delete;

		IGameScene() {}
		virtual ~IGameScene() {}

		virtual void load() = 0;
		virtual void processEvent(const sf::Event& evt) = 0;
		virtual void processEvents() = 0;
		virtual void update(sf::Time deltaTime) = 0;
		virtual void unload() = 0;

	private:
		//IGame* m_gamePtr;


		// Geerbt über Drawable
		

	};
}



