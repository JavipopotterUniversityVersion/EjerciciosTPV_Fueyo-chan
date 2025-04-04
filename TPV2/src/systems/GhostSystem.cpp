#include "GhostSystem.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"

GhostSystem::GhostSystem() {

}

GhostSystem::~GhostSystem() {

}

void GhostSystem::initSystem() {
	_pacMan = _mngr->getComponent<Transform>(_mngr->getEntities(ecs::hdlr::PACMAN)[0]);
}

void GhostSystem::update() {
	Vector2D posPM = _pacMan->_pos;
	for (Transform* ghost : _ghostsTr){
		ghost->_vel = (posPM - ghost->_pos).normalize() * 1.1f;
	}
}

