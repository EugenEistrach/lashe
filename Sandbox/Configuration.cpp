#include "stdafx.h"

#include "Configuration.h"

lshe::ResourceManager<sf::Texture, int> Configuration::textures;
lshe::ActionMap<int> Configuration::inputs;

void Configuration::initialize()
{
	initTextures();
	initPlayerInputs();
}

void Configuration::initTextures()
{
	
	textures.load(Textures::PLAYER, "assets/sprites/Ship.png");
	textures.load(Textures::PLAYER_SHEET, "assets/sprites/player.png");
}

void Configuration::initPlayerInputs()
{
	inputs.map(Direction::UP, lshe::Action(sf::Keyboard::Up));
	inputs.map(Direction::LEFT, lshe::Action(sf::Keyboard::Left));
	inputs.map(Direction::RIGHT, lshe::Action(sf::Keyboard::Right));
	inputs.map(Direction::DOWN, lshe::Action(sf::Keyboard::Down));
}
