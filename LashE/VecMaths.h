#pragma once

#include <SFML/System/Vector2.hpp>
#include <math.h>

namespace lshe
{
	class VecMaths
	{
	public:
		template<typename T>
		static float DotProduct(const sf::Vector2<T>& vec1, const sf::Vector2<T>& vec2)
		{
			return vec1.x * vec2.x + vec1.y * vec2.y;
		}

		template<typename T> 
		static sf::Vector2<T> Normalize(const sf::Vector2<T>& vec)
		{
			float length = std::sqrt((vec.x * vec.x) + (vec.y * vec.y));
			if (length != 0)
				return sf::Vector2<T>(vec.x / length, vec.y / length);
			else
				return vec;
		}
	};
}