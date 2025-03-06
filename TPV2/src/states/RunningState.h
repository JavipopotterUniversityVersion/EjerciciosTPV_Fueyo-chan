#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/VirtualTimer.h"
#include "../utils/Collisions.h"
#include "../facade/FighterUtils.h"
#include "../facade/AsteroidsUtils.h"
#include "../components/Transform.h"
#include "../components/Gun.h"
#include "../sdlutils/RandomNumberGenerator.h"


class RunningState : public GameState{
public:
	RunningState();
	~RunningState() {}

	float _waitTime = 5000.0f;
	AsteroidsUtils _fachadaAsteroides;
	FighterUtils _fachadaFighter;

	ecs::entity_t _player;
	Transform* _playerTr;
	std::vector<ecs::entity_t> _asteroids;
	Gun* _gunComponent;
	RandomNumberGenerator _rnd;

	void enter();
	void update();
	bool checkPlayerCollisions(Transform* playerTr, std::vector<ecs::entity_t> asteroids);
	void checkBulletCollisions(Gun* _gunComponent, std::vector<ecs::entity_t> asteroids);
	void leave();
};
