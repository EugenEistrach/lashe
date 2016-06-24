#pragma once

#include <SFML/System/Time.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/Drawable.hpp>

#include "anax/anax.hpp"

namespace lshe
{
	//class IGame;

	class IGameScene
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
		virtual void draw(sf::RenderTarget& renderTarget, float alpha) const = 0;
		virtual void unload() = 0;

	protected:
		anax::World m_EntityWorld;

	private:
		friend class SceneManager;

	
		void updateEntityWorld() { m_EntityWorld.refresh(); }

		//IGame* m_gamePtr;


		// Geerbt über Drawable
		

	};
}



