#include "GhostSystem.h"
#include "../components/Image.h"
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
		std::cout << _currentTime << std::endl;
	}

	for (Transform* ghost : _ghostsTr){
		ghost->_vel = (_pacMan->_pos - ghost->_pos).normalize() * 1.1f;
	}
}

ecs::entity_t GhostSystem::createGhost() {
	auto ghost = _mngr->addEntity();
	_mngr->setHandler(ecs::hdlr::GHOST, ghost);

	Transform* ghostTr = _mngr->addComponent<Transform>(ghost);
	_ghostsTr.push_back(ghostTr);
	auto s = 50.0f;
	auto x = (sdlutils().width() - s) / 2.0f;
	auto y = (sdlutils().height() - s) / 2.0f;
	ghostTr->init(Vector2D(x, y), Vector2D(), s, s, 0.0f);
	_mngr->addComponent<Image>(ghost, &sdlutils().images().at("ghost"));

	return ghost;
}

void GhostSystem::recieve(const Message& m)
{
	switch (m.id) {
	case _m_REGISTER_TIME:
		_currentTime = m.register_time_data.n;
		break;
	default:
		break;
	}
}