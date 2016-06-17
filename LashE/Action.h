#pragma once

#include <SFML/Window.hpp>

namespace lshe
{
	class Action
	{
	public:

		enum Type
		{
			REALTIME = 1,
			PRESSED = 1 << 1,
			RELEASED = 1 << 2
		};

		Action(const sf::Keyboard::Key& key, int type = Type::REALTIME | Type::PRESSED);
		Action(const sf::Mouse::Button& button, int type = Type::REALTIME | Type::PRESSED);

		Action(const Action& other);
		Action& operator=(const Action& other);

		bool test() const;

		bool operator==(const sf::Event & event) const;
		bool operator==(const Action& other) const;
	private:
		template<typename> friend class ActionTarget;
		sf::Event m_event;
		int m_type;
	};
}



