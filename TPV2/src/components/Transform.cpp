#include "Transform.h"

void Transform::set(float x, float y)
{
	_position.set(x, y);
}

void Transform::translate(float x, float y)
{
	_position.set(_position.getX() + x, _position.getY() + y);
}

void Transform::setVelocity(float x, float y)
{
	_velocity.set(x, y);
}

void Transform::update()
{
	_position.set(_position.getX() + _velocity.getX(), _position.getY() + _velocity.getY());
}