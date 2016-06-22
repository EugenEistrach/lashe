#pragma once
#include <LashE/IGameScene.h>
#include <LashE/AnimationSystem.h>
#include <LashE/SpriteRenderingSystem.h>

#include "Player.h"



class SceneGame : public lshe::IGameScene
{
public:
	SceneGame() {}
	virtual ~SceneGame() {}

	// Geerbt über IGameScene
	virtual void load() override;
	virtual void processEvent(const sf::Event & evt) override;
	virtual void processEvents() override;
	virtual void update(sf::Time deltaTime) override;
	virtual void unload() override;
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	Player m_player;

	lshe::AnimationSystem m_animationSystem;
	lshe::SpriteRenderingSystem m_spriteRenderingSystem;
	// Geerbt über IGameScene
	
};

