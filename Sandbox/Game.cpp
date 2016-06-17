#include "stdafx.h"
#include "Game.h"

Game::Game()
{
	
}


void Game::update(sf::Time delta)
{
	m_player.update(delta);
}

void Game::draw()
{
	m_window.draw(m_player);
}

void Game::processEvents()
{
	IGame::processEvents();
	m_player.processEvents();
}

Game::~Game()
{
}
