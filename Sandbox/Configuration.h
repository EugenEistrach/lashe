#pragma once
#include <LashE/ResourceManager.h>
#include <SFML/Graphics/Texture.hpp>
#include <LashE/ActionMap.h>

class Configuration
{
public:

	Configuration() = delete;
	Configuration(const Configuration&) = delete;
	Configuration& operator=(const Configuration&) = delete;

	enum Textures : int {PLAYER};
	static lshe::ResourceManager<sf::Texture, int> textures;

	enum PlayerInputs : int { UP, LEFT, RIGHT };
	static lshe::ActionMap<int> player_inputs;


	static void initialize();
private:
	static void initTextures();
	static void initPlayerInputs();
};
