#include "Transform.h"
#include <iostream>

Transform::Transform(float x, float y) : _position(x, y), _velocity(0, 0), _h(DEFAULT_SIZE), _w(DEFAULT_SIZE), _rotation() 
{
}

void Transform::initComponent()
{
	_originalPosition = getPos();
}

void Transform::set(float x, float y)
{
	_position.set(x, y);
}

Vector2D Transform::getVelocity()
{
	return _velocity;
}

void Transform::multVelocity(float mult)
{
	_velocity = _velocity * mult;
}

void Transform::translate(float x, float y)
{
	_position.set(_position.getX() + x, _position.getY() + y);
}

void Transform::setVelocity(float x, float y)
{
	_velocity.set(x, y);
}

void Transform::setVelocity(Vector2D velocity)
{
	_velocity = velocity;
}

void Transform::update()
{
	_position = _position + _velocity;
}

Vector2D Transform::up() const
{
	float rotInRad = (_rotation - 90) * 3.141516f / 180;
	Vector2D direction(cosf(rotInRad), sinf(rotInRad));
	return direction;
}