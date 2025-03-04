#pragma once
#include "AsteroidsFacade.h"
#include "../ecs/Manager.h"

class AsteroidsUtils : public AsteroidsFacade
{
public:
	AsteroidsUtils();
	~AsteroidsUtils() {}
	void create_asteroids(int n, Vector2D p) override;
	void remove_all_asteroids() override;
	void split_asteroid(ecs::Entity* a) override;
private:
	ecs::Manager* _manager;
};