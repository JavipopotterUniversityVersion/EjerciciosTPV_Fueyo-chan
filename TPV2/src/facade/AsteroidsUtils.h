#pragma once
#include "AsteroidsFacade.h"

class AsteroidsUtils : public AsteroidsFacade
{
public:
	AsteroidsUtils() {}
	~AsteroidsUtils() {}
	virtual void create_asteroids(int n) override;
	virtual void remove_all_asteroids() override;
	virtual void split_asteroid(ecs::Entity* a) override;
};