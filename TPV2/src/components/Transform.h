#pragma once
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"

class Transform : public ecs::Component
{
public:
	Transform(float x, float y) : _position(Vector2D(x,y)), _velocity(Vector2D(0,0)) {}
	~Transform() {};

	void set(float x, float y);
	float x() { return _position.getX(); };
	float y() { return _position.getY(); };
	Vector2D getPos() { return _position; }

	void translate(float x, float y);
	void setVelocity(float x, float y);
	void setVelocity(Vector2D velocity);
	Vector2D getVelocity() { return _velocity; };

	void setRotation(float rot) { _rotation = rot; };
	float getRotation() { return _rotation; };
	void addRotation(float rot) { _rotation += rot; };

	void setHeight(float h) { _h = h; }
	float getHeight() { return _h; }
	void setWidth(float w) { _w = w; }
	float getWidth() { return _w; }

	void update() override;

	Vector2D up() const;
	static const ecs::cmpId_t id = ecs::cmp::cmpId::TRANSFORM;
private:
	Vector2D _position;
	Vector2D _velocity;
	float _rotation;
	float _h;
	float _w;
};