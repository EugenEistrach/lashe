#include "stdafx.h"
#include "SceneGame.h"

#include <LashE/AnimationComponent.h>
#include <LashE/SpriteComponent.h>
#include <LashE/TransformComponent.h>

#include "Configuration.h"

enum AnimStates
{
	UP, DOWN, LEFT, RIGHT
};

void SceneGame::load()
{

	m_EntityWorld.addSystem(m_spriteRenderingSystem);
	m_EntityWorld.addSystem(m_animationSystem);

	m_animationSystem.setFps(3);

	auto& test = m_EntityWorld.createEntity();

	auto& transform = test.addComponent<lshe::TransformComponent>().transform;

	transform.setPosition(200, 200);

	auto& sprite = test.addComponent<lshe::SpriteComponent>().sprite;
	sprite.setTexture(Configuration::textures.get(Configuration::Textures::PLAYER_SHEET));

	auto& animation = test.addComponent<lshe::AnimationComponent>();
	animation.repeat = true;
	animation.isPlaying = true;

	animation.states[UP] = lshe::AnimationComponent::State(sf::Vector2u(0, 0), sf::Vector2u(3, 0));
	animation.states[LEFT] = lshe::AnimationComponent::State(sf::Vector2u(0, 32), sf::Vector2u(3, 0));
	animation.states[RIGHT] = lshe::AnimationComponent::State(sf::Vector2u(0, 64), sf::Vector2u(3, 0));
	animation.states[DOWN] = lshe::AnimationComponent::State(sf::Vector2u(0, 96), sf::Vector2u(3, 0));

	animation.playingState = UP;

	test.activate();
	
}

void SceneGame::processEvent(const sf::Event & evt)
{
	m_player.processEvent(evt);
}

void SceneGame::processEvents()
{
	m_player.processEvents();
}

void SceneGame::update(sf::Time deltaTime)
{
	m_animationSystem.update(deltaTime);
	m_player.update(deltaTime);
}

void SceneGame::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	m_player.draw(target, states);
	m_spriteRenderingSystem.draw(target, states);
}

void SceneGame::unload()
{
}


