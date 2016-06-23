#pragma once

#include "Components.h"


namespace lshe
{
	namespace ComponentFactory
	{	
		namespace Rpg_Maker
		{
			enum Type
			{
				R2K, R2K3, RXP, RVXAMV
			};

			enum SpriteType
			{
				SINGLE, SHEET
			};

			enum AnimStates
			{
				UP, DOWN, LEFT, RIGHT, UP_LEFT, UP_RIGHT, DOWN_LEFT, DOWN_RIGHT
			};

			AnimationComponent CreateAnimationComponent(Type rmtype, SpriteType spriteType)
			{

			}
		}
	};
}

