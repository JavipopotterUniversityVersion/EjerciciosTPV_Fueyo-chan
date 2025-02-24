#pragma once
#include "../ecs/Component.h"
class Transform;

class FighterCrtl : public ecs::Component
{
public:
	FighterCrtl() {};
	~FighterCrtl() {};
	void initComponent() override;
	void update() override;

private:
	Transform* t;
	const float ROTATION_SPEED = 0.5f;
	const float SPEED = 2.0f;
};