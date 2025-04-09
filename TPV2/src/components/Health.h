#pragma once
#include "../ecs/Component.h"
#include "../sdlutils/Texture.h"
#include "../sdlutils/SDLUtils.h"

struct Health : public ecs::Component
{
public:
	Health(int h) : _health(h) {};
	~Health() {};

	
	void LoseHealth(int h) { _health -= h; }
	void ResetHealth() { _health = 3; }
	int GetHealth() { return _health; }

private:
	int _health = 3;
};