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

	enum Textures : int {PLAYER, PLAYER_SHEET};
	static lshe::ResourceManager<sf::Texture, int> textures;

	enum Direction : int { UP, LEFT, RIGHT, DOWN};
	static lshe::ActionMap<int> inputs;


	static void initialize();
private:
	static void initTextures();
	static void initPlayerInputs();
};
