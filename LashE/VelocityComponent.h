#pragma once

#include "anax/Component.hpp"

#include <SFML/System/Vector2.hpp>

namespace lshe
{

	struct VelocityComponent : anax::Component
	{
#ifdef ANAX_VIRTUAL_DTORS_IN_COMPONENT
		virtual ~VelocityComponent() { }
#endif // ANAX_VIRTUAL_DTORS_IN_COMPONENT

		sf::Vector2f velocity;
	};
}