#pragma once

#include <vector>
#include <map>

#include <SFML/System/Vector2.hpp>

#include "anax/Component.hpp"

namespace lshe
{
	struct AnimationComponent : anax::Component
	{
		struct State
		{

			State() {}

			State(const sf::Vector2u& pStartPosition, const sf::Vector2u& pFrameAmount, unsigned int pFrameRate = 0) :
				startPosition(pStartPosition), frameAmount(pFrameAmount), frameRate(pFrameRate) {}
			/// The starting position of the animaton
			sf::Vector2u startPosition = sf::Vector2u(0,0);

			/// The amount of frames in each direction
			sf::Vector2u frameAmount = sf::Vector2u(3, 0);

			/// The frame rate you wish to play the state at
			/// Set this to 0 if you wish to use the animation frame rate
			unsigned int frameRate = 0;
		};

#ifdef ANAX_VIRTUAL_DTORS_IN_COMPONENT
		virtual ~AnimationComponent() { }
#endif // ANAX_VIRTUAL_DTORS_IN_COMPONENT

		/// Plays an animation
		void play(int state)
		{
			playingState = state;
			isPlaying = true;
		}

		/// Resets the animation
		void reset()
		{
			currentFrame.x = 0;
			currentFrame.y = 0;
		}

		/// Pauses the animation
		void pause()
		{
			isPlaying = false;
		}

		/// Stops the animation
		void stop()
		{
			pause();
			reset();
		}

		/// The size of each frame
		sf::Vector2u frameSize;

		/// A map to describe the animations the entity has
		std::map<int, State> states;

		/// The current frame number (in both directions)
		sf::Vector2u currentFrame = sf::Vector2u(0, 0);

		/// The currently playing animation state (represented as a string)
		int playingState;

		/// Determines if the animation is playing
		bool isPlaying = false;

		/// Determines whether or not the animation should repeat
		bool repeat = false;

	private:

		// used in implemenation
		double m_frameAccumulator;

		friend class AnimationSystem;

	};
}


// AnimStates = {UP, DOWN, LEFT, RIGHT}

// 
// comp.setFrameSize(vec4, 32, 32)
// comp.setFrames = vec(4, 4);
// comp.setSpeed = 