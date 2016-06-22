#pragma once

#include <SFML/Graphics.hpp>
#include <LashE/ActionTarget.h>

class Player : public sf::Drawable, public lshe::ActionTarget<int>
{
public:
	Player(const Player&) = delete;
	Player& operator=(const Player&) = delete;
	Player();

	template<typename ... Args>
	void setPosition(Args&& ... args)
	{
		m_ship.setPosition(std::forward<Args>(args) ...);
	}

	void update(sf::Time deltaTime);
	
	void processEvents();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
private:
	
	sf::Sprite m_ship;
	sf::Vector2f m_velocity;
	bool m_isMoving = false;
	int m_rotation = 0;
};

