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
	std::vector<ecs::entity_t> ghosts = _mngr->getEntities(ecs::grp::GHOST);

	if (ghosts.size() < MAX_GHOSTS && _currentTime >= _nextTime) {
		_nextTime = _currentTime + SPAWN_MARGIN;
		createGhost();
		std::cout << _currentTime << std::endl;
	}

	for (ecs::entity_t ghost : ghosts){
		Transform* gTr = _mngr->getComponent<Transform>(ghost);
		gTr->_vel = (_pacMan->_pos - gTr->_pos).normalize() * 1.1f;
		gTr->_pos = gTr->_pos + gTr->_vel;
	}
}

ecs::entity_t GhostSystem::createGhost() {
	auto ghost = _mngr->addEntity(ecs::grp::GHOST);

	Transform* ghostTr = _mngr->addComponent<Transform>(ghost);
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
		_currentTime = m.register_time_data.new_current_time;
		break;
	default:
		break;
	}
}