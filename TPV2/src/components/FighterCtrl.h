#pragma once
#include "../ecs/Component.h"

class FighterCrtl : public ecs::Component
{
public:
	FighterCrtl() {};
	~FighterCrtl() {};
	void update() override;

private:
};