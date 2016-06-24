#include "stdafx.h"
#include "SceneGame.h"

#include <LashE/AnimationComponent.h>
#include <LashE/SpriteComponent.h>
#include <LashE/TransformComponent.h>
#include <LashE/DirectionComponent.h>
#include <LashE/VelocityComponent.h>

const int MAX_PLAYERS = 10;

void SceneGame::load()
{

	m_EntityWorld.addSystem(m_spriteRenderingSystem);
	m_EntityWorld.addSystem(m_animationSystem);
	m_EntityWorld.addSystem(m_movementSystem);

	m_animationSystem.setFps(4);

	initPlayer();
	initInputs();
}

void SceneGame::processEvent(const sf::Event & evt)
{
	ActionTarget::processEvent(evt);
}

void SceneGame::processEvents()
{
	ActionTarget::processEvents();
}

void SceneGame::update(sf::Time deltaTime)
{

	updatePlayer(deltaTime);
	m_movementSystem.update(deltaTime);

	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		auto& anim = m_EntityWorld.getEntity(m_playerIds[i].index).getComponent<lshe::AnimationComponent>();
		auto& dir = m_EntityWorld.getEntity(m_playerIds[i].index).getComponent<lshe::DirectionComponent>();

		anim.playingState = dir.direction;
	}
	

	m_animationSystem.update(deltaTime);
}

void SceneGame::draw(sf::RenderTarget & target, float alpha) const
{
	m_spriteRenderingSystem.draw(target, alpha);
}

void SceneGame::initPlayer()
{

	

	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		auto& player = m_EntityWorld.createEntity();
		m_playerIds.push_back(player.getId());

		auto& transform = player.addComponent<lshe::TransformComponent>().transform;

		transform.setPosition(xDistrib(randEngine), yDistrib(randEngine));

		auto& sprite = player.addComponent<lshe::SpriteComponent>().sprite;
		sprite.setTexture(Configuration::textures.get(Configuration::Textures::PLAYER_SHEET));

		//auto& animation = player.addComponent<lshe::AnimationComponent>();

		lshe::AnimationComponent animation;


		animation.repeat = true;
		animation.isPlaying = false;
		animation.frameSize = sf::Vector2u(32, 32);
		animation.pingPong = true;

		animation.states[lshe::DirectionComponent::DOWN] = lshe::AnimationComponent::State(sf::Vector2u(0, 0), sf::Vector2u(3, 1));
		animation.states[lshe::DirectionComponent::LEFT] = lshe::AnimationComponent::State(sf::Vector2u(0, 32), sf::Vector2u(3, 1));
		animation.states[lshe::DirectionComponent::RIGHT] = lshe::AnimationComponent::State(sf::Vector2u(0, 64), sf::Vector2u(3, 1));
		animation.states[lshe::DirectionComponent::UP] = lshe::AnimationComponent::State(sf::Vector2u(0, 96), sf::Vector2u(3, 1));

		animation.playingState = lshe::DirectionComponent::LEFT;

		player.addComponent<lshe::AnimationComponent>(animation);

		player.addComponent<lshe::DirectionComponent>();
		player.addComponent<lshe::VelocityComponent>();

		player.activate();
	}

	

}

void SceneGame::initInputs()
{


}

void SceneGame::updatePlayer(sf::Time deltaTime)
{
	for (int i = 0; i < MAX_PLAYERS; i++)
	{
		auto& player = m_EntityWorld.getEntity(m_playerIds[i].index);
		auto& velocity = player.getComponent<lshe::VelocityComponent>();
		auto& dir = player.getComponent<lshe::DirectionComponent>();

		auto& anim = player.getComponent<lshe::AnimationComponent>();

		anim.isPlaying = false;
		velocity.velocity = sf::Vector2f(0.f, 0.f);

		float speed = 100.0f;


		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			velocity.velocity.y -= 1;
			anim.isPlaying = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			velocity.velocity.y += 1;
			anim.isPlaying = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		{
			velocity.velocity.x -= 1;
			anim.isPlaying = true;
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		{
			velocity.velocity.x += 1;
			anim.isPlaying = true;
		}

		velocity.velocity = lshe::VecMaths::Normalize(velocity.velocity) * speed;
	}
	
}

void SceneGame::unload()
{
}


