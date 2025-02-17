#pragma once
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"

class Transform : public Component
{
public:
	void Set(float x, float y);
	void Translate(float x, float y);
	void SetVelocity(float x, float y);
private:
	Vector2D _position;
	Vector2D _velocity;
};