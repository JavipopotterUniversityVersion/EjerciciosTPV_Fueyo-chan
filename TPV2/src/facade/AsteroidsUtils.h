#pragma once
#include "AsteroidsFacade.h"

class AsteroidsUtils : public AsteroidsFacade
{
public:
	AsteroidsUtils() {}
	~AsteroidsUtils() {}
	virtual void create_asteroids(int n) override;
	virtual void remove_all_asteroids() override;
	virtual void split_astroid(ecs::Entity* a) override;
};