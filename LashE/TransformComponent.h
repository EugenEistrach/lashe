#pragma once

#include "anax/Component.hpp"
#include <sfml/Graphics/Transformable.hpp>

namespace lshe 
{
	struct TransformComponent : anax::Component
	{
#ifdef ANAX_VIRTUAL_DTORS_IN_COMPONENT
		virtual ~TransformComponent() { }
#endif // ANAX_VIRTUAL_DTORS_IN_COMPONENT

		sf::Transformable transform;
	};
}