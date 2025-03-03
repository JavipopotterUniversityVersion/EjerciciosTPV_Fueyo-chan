// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

#include <vector>

#include "../ecs/Entity.h"
#include "../ecs/Manager.h"

class Game {
public:
	Game();
	virtual ~Game();
	void init();
	void start();
private:
	ecs::Manager* _manager;
	std::vector<ecs::entity_t> _entities;
};

