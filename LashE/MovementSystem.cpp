#include "MovementSystem.h"
#include "DirectionComponent.h"

namespace lshe
{
	void MovementSystem::update(sf::Time deltaTime)
	{
		auto& entities = getEntities();
		for (auto& entity : entities)
		{
			auto& transform = entity.getComponent<TransformComponent>().transform;
			auto& velocity = entity.getComponent<VelocityComponent>().velocity;
			
			if (velocity != sf::Vector2f(0.f, 0.f))
			{
				if (entity.hasComponent<DirectionComponent>())
				{
					entity.getComponent<DirectionComponent>().setDirFromVec(velocity);
				}
				transform.move(velocity * deltaTime.asSeconds());
			}
		}
	}
}


