// This file is part of the course TPV2@UCM - Samir Genaim

#include "CollisionsSystem.h"

#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../utils/Collisions.h"
#include "StarsSystem.h"
#include "../sdlutils/SDLUtils.h"

CollisionsSystem::CollisionsSystem() {
	// TODO Auto-generated constructor stub

}

CollisionsSystem::~CollisionsSystem() {
	// TODO Auto-generated destructor stub
}

void CollisionsSystem::initSystem() {
}

void CollisionsSystem::update() {

	// the PacMan's Transform
	//
	auto pm = _mngr->getHandler(ecs::hdlr::PACMAN);
	auto pTR = _mngr->getComponent<Transform>(pm);
	SDL_Rect playerRect = build_sdlrect(pTR->_pos, pTR->_width, pTR->_height);

	// For safety, we traverse with a normal loop until the current size. In this
	// particular case we could use a for-each loop since the list stars is not
	// modified.
	//
	auto &ghosts = _mngr->getEntities(ecs::grp::GHOST);
	auto new_current_time = ghosts.size();

	for (auto i = 0u; i < new_current_time; i++) {
		auto ghostTr = _mngr->getComponent<Transform>(ghosts[i]);
		SDL_Rect ghostRect = build_sdlrect(ghostTr->_pos, ghostTr->_width, ghostTr->_height);

		SDL_Rect result;
		if (SDL_IntersectRect(&playerRect, &ghostRect, &result)){
			Message m;
			m.id = _m_PACMAN_GHOST_COLLISION;
			m.pacman_ghost_collision_data.pacman_wins = isPacManInmune;
			_mngr->send(m);

			if (isPacManInmune) _mngr->setAlive(ghosts[i], false);
		}
	}
}

void CollisionsSystem::recieve(const Message& m){
	switch (m.id) {
	case _m_IMMUNITY_START:
		isPacManInmune = true;
		break;
	case _m_IMMUNITY_END:
		isPacManInmune = false;
		break;
	default:
		break;
	}
}