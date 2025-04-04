#pragma once
#include "../ecs/System.h"

class InmunitySystem : public ecs::System
{
public:
	InmunitySystem();
	virtual ~InmunitySystem();
	void initSystem() override;
	void update() override;
private:
};