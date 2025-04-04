#include "GhostSystem.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"

GhostSystem::GhostSystem() {

}

GhostSystem::~GhostSystem() {

}

void GhostSystem::initSystem() {
	_pacMan = _mngr->getComponent<Transform>(_mngr->getEntities(ecs::hdlr::PACMAN)[0]);
}

void GhostSystem::update() {

	if (_ghostsTr.size() < MAX_GHOSTS && _currentTime >= _nextTime) {
		_nextTime = _currentTime + SPAWN_MARGIN;
		_ghostsTr.push_back(_mngr->getComponent<Transform>(createGhost()));
	}

	for (Transform* ghost : _ghostsTr){
		ghost->_vel = (_pacMan->_pos - ghost->_pos).normalize() * 1.1f;
	}
}

ecs::entity_t GhostSystem::createGhost() {
	return nullptr;
}