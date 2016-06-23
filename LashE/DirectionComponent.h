#pragma once

#include <SFML/System/Vector2.hpp>

#include "anax/Component.hpp"

#include "VecMaths.h"

namespace lshe
{
	struct DirectionComponent : anax::Component
	{
#ifdef ANAX_VIRTUAL_DTORS_IN_COMPONENT
		virtual ~DirectionComponent() { }
#endif // ANAX_VIRTUAL_DTORS_IN_COMPONENT

		enum Direction {UP, DOWN, LEFT, RIGHT};

		const sf::Vector2f UP_VEC = sf::Vector2f(0.f, -1.f);
		const sf::Vector2f DOWN_VEC = sf::Vector2f(0.f, 1.f);
		const sf::Vector2f LEFT_VEC = sf::Vector2f(-1.f, 0.f);
		const sf::Vector2f RIGHT_VEC = sf::Vector2f(1.f, 0.f);

		Direction direction;

		void setDirFromVec(const sf::Vector2f& dir)
		{
			if (dir.x == 0 && dir.y == 0)
				return;
			Direction directions[] = { UP, DOWN, LEFT, RIGHT };
			sf::Vector2f vecDirections[] = {UP_VEC, DOWN_VEC, LEFT_VEC, RIGHT_VEC};
			
			auto maxDot = -std::numeric_limits<float>::infinity();

			for (int i = 0; i < 4; i++)
			{
				auto t = VecMaths::DotProduct(dir, vecDirections[i]);
				if (t > maxDot)
				{
					maxDot = t;
					direction = directions[i];
				}
			}
		}

		sf::Vector2f getVelocity() 
		{
			auto vel = sf::Vector2f(0, 0);

			switch (direction)
			{
			case UP:
				vel.y = -1;
				break;
			case DOWN:
				vel.y = 1;
				break;
			case LEFT:
				vel.x = -1;
				break;
			case RIGHT:
				vel.y = 1;
				break;
			}
			return vel;
		}
	};
}