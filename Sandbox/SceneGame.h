#pragma once

#include <vector>

#include <LashE/IGameScene.h>
#include <LashE/AnimationSystem.h>
#include <LashE/SpriteRenderingSystem.h>
#include <LashE/MovementSystem.h>
#include <LashE/ActionTarget.h>
#include "Configuration.h"

#include <random>

class SceneGame : public lshe::IGameScene, public lshe::ActionTarget<int>
{
public:
	SceneGame() : ActionTarget(Configuration::inputs){}
	virtual ~SceneGame() {}

	// Geerbt über IGameScene
	virtual void load() override;
	virtual void processEvent(const sf::Event & evt) override;
	virtual void processEvents() override;
	virtual void update(sf::Time deltaTime) override;
	virtual void unload() override;
	// Geerbt über IGameScene
	virtual void draw(sf::RenderTarget & renderTarget, float alpha) const override;

private:
	lshe::AnimationSystem m_animationSystem;
	lshe::SpriteRenderingSystem m_spriteRenderingSystem;
	lshe::MovementSystem m_movementSystem;
	// Geerbt über IGameScene

	std::vector<anax::Entity::Id> m_playerIds;

	std::mt19937 randEngine;
	std::uniform_int_distribution<int> xDistrib = std::uniform_int_distribution<int>(50, 1390);
	std::uniform_int_distribution<int> yDistrib = std::uniform_int_distribution<int>(50, 850);


	void initPlayer();
	void initInputs();
	void updatePlayer(sf::Time deltaTime);



	

};

