#pragma once
#include "../ecs/Entity.h"
#include "../utils/Vector2D.h"

class AsteroidsFacade {
public:
	AsteroidsFacade() {
	}
	virtual ~AsteroidsFacade() {
	}
	virtual void create_asteroids(int n) = 0;
	virtual void remove_all_asteroids() = 0;
	virtual void split_asteroid(ecs::Entity* a) = 0;
};