#pragma once

#include <SFML/System/Time.hpp>

#include "anax/system.hpp"

#include "TransformComponent.h"
#include "VelocityComponent.h"


namespace lshe
{
	struct TransformComponent;
	struct VelocityComponent;

	class MovementSystem : public anax::System < anax::Requires<TransformComponent, VelocityComponent>>
	{
	public:
		void update(sf::Time deltaTime);
	};

}