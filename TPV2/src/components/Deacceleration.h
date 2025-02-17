#pragma once
#include "../ecs/Component.h"

class Deacceleration : public ecs::Component
{
public:
	Deacceleration() {}
	~Deacceleration() {}
	void update() override;
private:
	float _slowFactor = 0.995f;
};