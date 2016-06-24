#include "AnimationSystem.h"

#include <iostream>

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
				auto curFrameX = animation.currentFrame % animationState->frameAmount.x;
				auto curFrameY = animation.currentFrame / animationState->frameAmount.x;
				auto maxFrames = animationState->frameAmount.x * animationState->frameAmount.y;

				float multiplicator = 1.0f;
				// go backwards if ping pong animation and max reached
				if (animation.pingPong && animation.m_animateBackward)
					multiplicator = -1.0f;

				// accumulate animation frame over delta time with fps as speed
				animation.m_frameAccumulator += deltaTime.asSeconds() * (animationState->frameRate == 0 ? getFps() : animationState->frameRate) * multiplicator;
				animation.currentFrame = static_cast<int>(animation.m_frameAccumulator);

				if (animation.pingPong)
				{
					// Toggle backwards or forwards depending on accumulator state
					if (animation.m_animateBackward)
					{
						if (animation.m_frameAccumulator <= 0)
						{
							animation.m_animateBackward = false;
							animation.currentFrame = 1;
							animation.m_frameAccumulator = 1.0f;
						}
					}
					else
					{
						if (animation.m_frameAccumulator >= maxFrames)
						{
							animation.m_animateBackward = true;
							animation.currentFrame = maxFrames - 1;
							animation.m_frameAccumulator = maxFrames - 1;
						}
					}
				}
				else
				{
					// keep the values valid
					if (animation.m_frameAccumulator >= maxFrames || animation.m_frameAccumulator <= 0)
					{
						animation.currentFrame = 0;
						animation.m_frameAccumulator = 0.0f;
					}	
				}

				animation.isPlaying = animation.repeat;
			}

			if (animationState)
			{
				auto curFrameX = animation.currentFrame % animationState->frameAmount.x;
				auto curFrameY = animation.currentFrame / animationState->frameAmount.x;
				
				// calculate texture rect
				sf::IntRect rect(sf::Vector2i(animationState->startPosition.x + animation.frameSize.x * curFrameX,
					animationState->startPosition.y + animation.frameSize.y * curFrameY),
					sf::Vector2i(animation.frameSize));
				sprite.setTextureRect(rect);
			}
		}
	}
}

