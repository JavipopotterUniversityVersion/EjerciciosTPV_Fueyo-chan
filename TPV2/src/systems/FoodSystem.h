#pragma once
#include "../ecs/System.h"
#include "../sdlutils/RandomNumberGenerator.h"

class FoodSystem : public ecs::System
{
public:
	FoodSystem();
	virtual ~FoodSystem();
	void initSystem() override;
	void update() override;
private:
	void createFruit(int x, int y);
	static int constexpr GRID_SIZE = 100;
	RandomNumberGenerator _rng;
};

