#include "SpriteRenderingSystem.h"

#include <iostream>

namespace lshe
{
	void SpriteRenderingSystem::draw(sf::RenderTarget& renderTarget, sf::RenderStates& states) const
	{
		auto entities = getEntities();

		for (auto& entity : entities)
		{
			auto& sprite = entity.getComponent<SpriteComponent>().sprite;
			auto& transform = entity.getComponent<TransformComponent>().transform;

			

				
			sprite.setPosition(transform.getPosition());
			sprite.setOrigin(transform.getOrigin());
			sprite.setRotation(transform.getRotation());
			sprite.setScale(transform.getScale());

			renderTarget.draw(sprite, states);

			//render.draw(sprite, transform.getTransform());
		}
	}
}