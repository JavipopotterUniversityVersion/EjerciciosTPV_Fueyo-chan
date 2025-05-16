#include "GhostSystem.h"
#include "../components/FramedImage.h"
#include "../game/AnimationUtility.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"

GhostSystem::GhostSystem() : _currentGhostsFrameRange(AnimationUtility::getRedGhost()), _pacMan(nullptr) {

}

GhostSystem::~GhostSystem() {

}

void GhostSystem::initSystem() {
	_pacMan = _mngr->getComponent<Transform>(_mngr->getEntities(ecs::hdlr::PACMAN)[0]);
}

void GhostSystem::restartSystem() {
	std::vector<ecs::entity_t> ghosts = _mngr->getEntities(ecs::grp::GHOST);

	for (ecs::entity_t ghost : ghosts) {
		_mngr->setAlive(ghost, false);
	}
	_currentTime = 0;
	_nextTime = SPAWN_MARGIN;
}
void GhostSystem::update() {
	std::vector<ecs::entity_t> ghosts = _mngr->getEntities(ecs::grp::GHOST);

	if (ghosts.size() < MAX_GHOSTS && _currentTime >= _nextTime && _ghostSpawn) {
		_nextTime = _currentTime + SPAWN_MARGIN;
		createGhost();
		std::cout << _currentTime << std::endl;
	}

	
	for (ecs::entity_t ghost : ghosts){
		Transform* gTr = _mngr->getComponent<Transform>(ghost);

		// 1 / 200 = 0.005
		if (sdlutils().rand().nextInt(0, 200) == 0 || (_pacMan->_pos - gTr->_pos).magnitude() < 0.5f) {
			gTr->_vel = (_pacMan->_pos - gTr->_pos).normalize() * 1.1f;
		}

		gTr->_pos = gTr->_pos + gTr->_vel;
	}
}

ecs::entity_t GhostSystem::createGhost() {
	auto ghost = _mngr->addEntity(ecs::grp::GHOST);

	Vector2D pos = Vector2D();
	int rndBorder = sdlutils().rand().nextInt(0, 4);
	if (rndBorder == 0) pos = { 0.0f, 0.0f}; //Esquina arriba izq.
	else if (rndBorder == 1) pos = { float(sdlutils().width() - 40), 0.0f }; //Esquina arriba der.
	else if (rndBorder == 2) pos = { 0.0f, float(sdlutils().height() - 40)}; //Esquina abajo izq.
	else if (rndBorder == 3) pos = { float(sdlutils().width() - 40), float(sdlutils().height() - 40) }; //Borde abajo
	_mngr->addComponent<Transform>(ghost, pos, (_pacMan->_pos - pos).normalize() * 1.1f, 40.0f, 40.0f, 0.0f);
	_mngr->addComponent<FramedImage>(ghost, _currentGhostsFrameRange);

	return ghost;
}

void GhostSystem::recieve(const Message& m)
{
	switch (m.id) {
	{
		std::vector<ecs::entity_t> ghosts = _mngr->getEntities(ecs::grp::GHOST);
		_currentGhostsFrameRange = AnimationUtility::getVulnerableGhost();
		for (ecs::entity_t ghost : ghosts) _mngr->getComponent<FramedImage>(ghost)->setFrameRange(_currentGhostsFrameRange);
		_ghostSpawn = false;
	}
		break;
	case _m_IMMUNITY_END:
	{
		std::vector<ecs::entity_t> ghosts = _mngr->getEntities(ecs::grp::GHOST);
		_currentGhostsFrameRange = AnimationUtility::getRedGhost();
		for (ecs::entity_t ghost : ghosts) _mngr->getComponent<FramedImage>(ghost)->setFrameRange(_currentGhostsFrameRange);
		_ghostSpawn = true;
	}
		break;
	default:
		break;
	}
}