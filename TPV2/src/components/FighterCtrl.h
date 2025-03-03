#pragma once
#include "../ecs/Component.h"
class Transform;

class FighterCrtl : public ecs::Component
{
public:
	FighterCrtl() : t() {};
	~FighterCrtl() {};
	void initComponent() override;
	void update() override;

	__CMPID_DECL__(ecs::cmp::FIGHTER_CTRL)

private:
	Transform* t;
	const float ROTATION_SPEED = 0.5f;
	const float SPEED = 2.0f;
};