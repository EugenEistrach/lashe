#include "SpriteRenderingSystem.h"

#include <iostream>

namespace lshe
{
	void SpriteRenderingSystem::draw(sf::RenderTarget & renderTarget, float alpha) const
	{
		auto entities = getEntities();

		for (auto& entity : entities)
		{
			auto& sprite = entity.getComponent<SpriteComponent>().sprite;
			auto& transform = entity.getComponent<TransformComponent>();

			if (!transform.initialized)
			{
				transform.m_oldTransform = transform.m_oldTransform;
				transform.initialized = true;
			}
			auto pos = transform.transform.getPosition() * alpha + transform.m_oldTransform.getPosition() * (1.0f - alpha);

			// set sprites transform from transform component	
			sprite.setPosition(pos);
			sprite.setOrigin(transform.transform.getOrigin());
			sprite.setRotation(transform.transform.getRotation());
			sprite.setScale(transform.transform.getScale());

			renderTarget.draw(sprite);

			transform.m_oldTransform = transform.transform;
		}

	}
}