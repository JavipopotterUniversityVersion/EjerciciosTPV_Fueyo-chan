#pragma once
#include "../ecs/Component.h"
#include "../sdlutils/Texture.h"
#include "../sdlutils/SDLUtils.h"

class Health : public ecs::Component
{
public:
	Health(int h) : _health(h), _tex(&sdlutils().images().at("fire")) {};
	~Health();

	void render() override;
	void LoseHealth(int h) { _health -= h; }
	void ResetHealth() { _health = 3; }
	const int GetHealth() { return _health; }

	__CMPID_DECL__(ecs::cmp::HEALTH)

private:
	static constexpr int HEART_SIZE = 32;
	int _health = 3;
	Texture* _tex;
};