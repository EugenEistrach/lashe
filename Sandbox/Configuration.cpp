#include "stdafx.h"

#include "Configuration.h"

lshe::ResourceManager<sf::Texture, int> Configuration::textures;
lshe::ActionMap<int> Configuration::player_inputs;

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
	player_inputs.map(PlayerInputs::UP, lshe::Action(sf::Keyboard::Up));
	player_inputs.map(PlayerInputs::LEFT, lshe::Action(sf::Keyboard::Left));
	player_inputs.map(PlayerInputs::RIGHT, lshe::Action(sf::Keyboard::Right));
}
