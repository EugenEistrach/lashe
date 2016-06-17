#include "stdafx.h"
#include "Player.h"
#include "SFML/System.hpp"

#define  _USE_MATH_DEFINES
#include <math.h>
#include "Configuration.h"

Player::Player() : ActionTarget(Configuration::player_inputs)
{
	m_ship.setTexture(Configuration::textures.get(Configuration::PLAYER));
	m_ship.setOrigin(49.5f, 37.5f);

	bind(Configuration::PlayerInputs::UP, [this](const sf::Event&)
	{
		m_isMoving = true;
	});

	bind(Configuration::PlayerInputs::LEFT, [this](const sf::Event&)
	{
		m_rotation += 1;
	});

	bind(Configuration::PlayerInputs::RIGHT, [this](const sf::Event&)
	{
		m_rotation -= 1;
	});
}

void Player::update(sf::Time deltaTime)
{
	float seconds = deltaTime.asSeconds();
	if (m_rotation != 0)
	{
		float angle = m_rotation * 180 * seconds;
		m_ship.rotate(angle);
	}

	if (m_isMoving)
	{
		float angle = m_ship.getRotation() / 180 * M_PI - M_PI / 2;
		m_velocity += sf::Vector2f(std::cos(angle), std::sin(angle)) * 60.0f * seconds; 
		
	}

	m_ship.move(m_velocity * seconds);
}

void Player::processEvents()
{
	m_isMoving = false;
	m_rotation = 0;
	ActionTarget::processEvents();
}

void Player::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(m_ship, states);
}
