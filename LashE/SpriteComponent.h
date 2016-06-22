#pragma once

#include "anax/Component.hpp"
#include <sfml/Graphics/Sprite.hpp>

namespace lshe
{
	struct SpriteComponent : anax::Component
	{
#ifdef ANAX_VIRTUAL_DTORS_IN_COMPONENT
		virtual ~SpriteComponent() { }
#endif // ANAX_VIRTUAL_DTORS_IN_COMPONENT

		sf::Sprite sprite;
	};
}
