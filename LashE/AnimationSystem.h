#pragma once

#include <SFML/System/Time.hpp>

#include "anax/system.hpp"

#include "SpriteComponent.h"
#include "AnimationComponent.h"

namespace lshe
{
	class AnimationSystem : public anax::System <anax::Requires<SpriteComponent, AnimationComponent>>
	{
	public:

		void update(sf::Time deltaTime);
		void setFps(unsigned int fps) { m_fps = fps; }
		unsigned int getFps() const { return m_fps; }

	private:
		unsigned int m_fps;
	};

}