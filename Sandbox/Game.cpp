#include "stdafx.h"
#include "Game.h"
#include "SceneGame.h"

Game::~Game()
{
}

void Game::init()
{
	m_sceneManager.call<SceneGame>();
}
