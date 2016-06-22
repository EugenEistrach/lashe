#include "MovementSystem.h"


namespace lshe
{
	void MovementSystem::update(sf::Time deltaTime)
	{
		auto& entities = getEntities();
		for (auto& entity : entities)
		{
			auto& transform = entity.getComponent<TransformComponent>().transform;
			auto& velocity = entity.getComponent<VelocityComponent>().velocity;

			transform.move(velocity * deltaTime.asSeconds());
		}
	}
}


