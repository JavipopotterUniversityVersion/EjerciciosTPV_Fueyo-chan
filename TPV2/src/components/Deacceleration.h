#pragma once
#include "../ecs/Component.h"
#include "Transform.h"

class Deacceleration : public ecs::Component
{
public:
	Deacceleration() {}
	~Deacceleration() {}
	void update() override;
	void initComponent() override;
private:
	float _slowFactor = 0.995f;
	Transform* t;
};