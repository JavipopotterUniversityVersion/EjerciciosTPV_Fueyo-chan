#pragma once
#include "../systems/InmunitySystem.h"
#include "../sdlutils/SDLUtils.h"
#include "../ecs/Manager.h"

InmunitySystem::InmunitySystem() {}
InmunitySystem::~InmunitySystem() {}

void InmunitySystem::initSystem() {

}

void InmunitySystem::update() {
	if (isInmune && sdlutils().currTime() >= _nextTime) {
		isInmune = false;
		Message m;
		m.id = _m_IMMUNITY_END;
		_mngr->send(m);
	}
}

void InmunitySystem::recieve(const Message& m) {
	switch (m.id) {
	case _m_IMMUNITY_START:
		isInmune = true;
		_nextTime = sdlutils().currTime() + INMUNE_TIME;
		break;
	case _m_PACMAN_FOOD_COLLISION:
		if (m.pacman_food_collision_data.is_wonder_and_active)
		{
			Message m;
			m.id = _m_IMMUNITY_START;
			_mngr->send(m);
		}
		break;
	default:
		break;
	}
}