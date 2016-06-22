#include "stdafx.h"
#include "SceneGame.h"


void SceneGame::load()
{
}

void SceneGame::processEvent(const sf::Event & evt)
{
	m_player.processEvent(evt);
}

void SceneGame::processEvents()
{
	m_player.processEvents();
}

void SceneGame::update(sf::Time deltaTime)
{
	m_player.update(deltaTime);
}

void SceneGame::draw(sf::RenderTarget & target, sf::RenderStates states) const
{
	m_player.draw(target, states);
}

void SceneGame::unload()
{
}


