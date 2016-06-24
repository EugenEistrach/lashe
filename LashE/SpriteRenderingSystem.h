#pragma once

#include "anax/System.hpp"

#include <SFML/Graphics/RenderTarget.hpp><>

#include "SpriteComponent.h"
#include "TransformComponent.h"

namespace lshe
{
	struct SpriteComponent;
	struct TransformComponent;

	class SpriteRenderingSystem : public anax::System<anax::Requires<SpriteComponent, TransformComponent>>
	{
	public:
		void draw(sf::RenderTarget& renderTarget, float alpha) const;
	};
}