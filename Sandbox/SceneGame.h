#pragma once
#include <LashE/IGameScene.h>
#include <LashE/AnimationSystem.h>
#include <LashE/SpriteRenderingSystem.h>
#include <LashE/MovementSystem.h>
#include <LashE/ActionTarget.h>
#include "Configuration.h"

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
	virtual void draw(sf::RenderTarget & target, sf::RenderStates states) const override;

private:
	lshe::AnimationSystem m_animationSystem;
	lshe::SpriteRenderingSystem m_spriteRenderingSystem;
	lshe::MovementSystem m_movementSystem;
	// Geerbt über IGameScene

	anax::Entity::Id m_playerId;

	void initPlayer();
	void initInputs();
	void updatePlayer(sf::Time deltaTime);


};

