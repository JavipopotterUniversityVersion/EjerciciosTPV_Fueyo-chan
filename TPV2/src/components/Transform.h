#pragma once
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"

class Transform : public ecs::Component
{
public:
	Transform(float x, float y);
	~Transform() {};

	void set(float x, float y);
	float x() { return _position.getX(); };
	float y() { return _position.getY(); };
	Vector2D& getPos() { return _position; }

	void translate(float x, float y);
	void setVelocity(float x, float y);
	void setVelocity(Vector2D velocity);
	Vector2D getVelocity() { return _velocity; };

	void setRotation(float rot) { _rotation = rot; };
	float getRotation() { return _rotation; };
	void addRotation(float rot) { _rotation += rot; };

	void initComponent() override;

	inline void setWidthAndHeight(float wh) { _h = _w = wh; }
	inline void setHeight(float h) { _h = h; }
	inline float getHeight() { return _h; }
	inline void setWidth(float w) { _w = w; }
	inline float getWidth() { return _w; }

	void update() override;
	inline void resetPosition() { _position = _originalPosition; }

	Vector2D up() const;
	__CMPID_DECL__(ecs::cmp::TRANSFORM)

private:
	Vector2D _position;
	Vector2D _velocity;
	float _rotation;
	float _h;
	float _w;

	Vector2D _originalPosition;
};