#pragma once
#include "../ecs/Component.h"

class Health : public ecs::Component
{
public:
	Health(int h) : _health(h);
	~Health();

	void ShowHealth();
	void LoseHealth(int h) { _health -= h; }
	void ResetHealth() { _health = 3; }
	int GetHealth() { return _health; }

private:
	int _health = 3;
};