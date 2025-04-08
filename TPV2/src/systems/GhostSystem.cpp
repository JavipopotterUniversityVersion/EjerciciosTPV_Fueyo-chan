#include "GhostSystem.h"
#include "../components/FramedImage.h"
#include "../game/AnimationUtility.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"

GhostSystem::GhostSystem() : _currentGhostsFrameRange(AnimationUtility::getRedGhost()) {

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

	/*Transform* ghostTr = _mngr->addComponent<Transform>(ghost);
	auto s = 50.0f;
	auto x = (sdlutils().width() - s) / 2.0f;
	auto y = (sdlutils().height() - s) / 2.0f;
	ghostTr->init(Vector2D(x, y), Vector2D(), s, s, 0.0f);*/
	
	Vector2D pos = Vector2D();
	int rndBorder = sdlutils().rand().nextInt(0, 4);
	if (rndBorder == 0) pos = { 10.0f, float(sdlutils().rand().nextInt(10, sdlutils().height()-10)) }; //Borde izq.
	else if (rndBorder == 1) pos = { float(sdlutils().width()-10), float(sdlutils().rand().nextInt(10, sdlutils().height()-10)) }; //Borde der.
	else if (rndBorder == 2) pos = { float(sdlutils().rand().nextInt(10, sdlutils().width()-10)), 10.0f }; //Borde arriba
	else if (rndBorder == 3) pos = { float(sdlutils().rand().nextInt(10, sdlutils().width()-10)), float(sdlutils().height()-10) }; //Borde abajo
	Transform* tr = _mngr->addComponent<Transform>(ghost, pos, Vector2D{}, 50.0f, 50.0f, 0.0f);
	_mngr->addComponent<FramedImage>(ghost, _currentGhostsFrameRange);

	return ghost;
}

void GhostSystem::recieve(const Message& m)
{
	switch (m.id) {
	case _m_REGISTER_TIME:
		_currentTime = m.register_time_data.new_current_time;
		break;
	case _m_IMMUNITY_START:
	{
		std::vector<ecs::entity_t> ghosts = _mngr->getEntities(ecs::grp::GHOST);
		_currentGhostsFrameRange = AnimationUtility::getVulnerableGhost();
		for (ecs::entity_t ghost : ghosts) _mngr->getComponent<FramedImage>(ghost)->setFrameRange(_currentGhostsFrameRange);
	}
		break;
	case _m_IMMUNITY_END:
	{
		std::vector<ecs::entity_t> ghosts = _mngr->getEntities(ecs::grp::GHOST);
		_currentGhostsFrameRange = AnimationUtility::getRedGhost();
		for (ecs::entity_t ghost : ghosts) _mngr->getComponent<FramedImage>(ghost)->setFrameRange(_currentGhostsFrameRange);
	}
		break;
	default:
		break;
	}
}