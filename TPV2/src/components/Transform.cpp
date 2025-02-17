#include "Transform.h"

void Transform::Set(float x, float y)
{
	_position.set(x, y);
}

void Transform::Translate(float x, float y)
{
	_position.set(_position.getX() + x, _position.getY() + y);
}

void Transform::SetVelocity(float x, float y)
{
	_velocity.set(x, y);
}