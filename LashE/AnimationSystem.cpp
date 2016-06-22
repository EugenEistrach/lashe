#include "AnimationSystem.h"


namespace lshe
{
	void AnimationSystem::update(sf::Time deltaTime)
	{
		auto& entities = getEntities();
		for (auto& entity : entities)
		{
			auto& animation = entity.getComponent<AnimationComponent>();
			auto& sprite = entity.getComponent<SpriteComponent>().sprite;

			AnimationComponent::State* animationState = nullptr;
			if (animation.states.count(animation.playingState))
			{
				animationState = &animation.states[animation.playingState];
			}

			if (animation.isPlaying && animationState)
			{
				animation.m_frameAccumulator += deltaTime.asSeconds() * (animationState->frameRate == 0 ? getFps() : animationState->frameRate);
				animation.currentFrame.x = (int)animation.m_frameAccumulator;

				if (animation.currentFrame.x >= animationState->frameAmount.x)
				{
					// go to the next row (if necessary)
					if (animationState->frameAmount.y)
					{
						if (animation.currentFrame.y >= animationState->frameAmount.y)
						{
							animation.currentFrame.y = 0;
						}
						else
						{
							++animation.currentFrame.y;
						}
					}

					// reset the animation
					animation.currentFrame.x = 0;
					animation.m_frameAccumulator = 0;

					animation.isPlaying = animation.repeat;
				}
			}

			if (animationState)
			{
				sf::IntRect rect(sf::Vector2i(animationState->startPosition.x + animation.frameSize.x * (int)animation.currentFrame.x,
					animationState->startPosition.y + animation.frameSize.y * (int)animation.currentFrame.y),
					sf::Vector2i(animation.frameSize));

				sprite.setTextureRect(rect);
			}
		}
	}
}

