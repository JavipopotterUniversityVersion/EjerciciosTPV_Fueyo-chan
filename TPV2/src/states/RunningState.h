#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../sdlutils/InputHandler.h"
#include "../systems/CollisionsSystem.h"
#include "../systems/FoodSystem.h"
#include "../systems/GameCtrlSystem.h"
#include "../systems/GhostSystem.h"
#include "../systems/InmunitySystem.h"
#include "../systems/PacManSystem.h"
#include "../systems/RenderSystem.h"

class RunningState : public GameState {
public:
	RunningState();
	~RunningState() {}

	float _waitTime = 5000.0f;

	ecs::entity_t _player;
	CollisionsSystem* _collisionSystem;
	FoodSystem* _foodSystem;
	GhostSystem* _ghostSystem;
	PacManSystem* _pacManSystem;
	InmunitySystem* _inmunitySystem;
	RenderSystem* _renderSystem;

	void enter();
	void update();
	void leave();
};
