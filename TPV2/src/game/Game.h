// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

#include <vector>

#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#include "../utils/Singleton.h"

class Game : public Singleton<Game> {
public:
	Game();
	virtual ~Game();
	bool init();
	void start();
	inline ecs::Manager* getManager() { return _manager; }
private:
	ecs::Manager* _manager;
	std::vector<ecs::entity_t> _entities;
};

