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

	auto pm = _mngr->getHandler(ecs::hdlr::PACMAN);
	auto pTR = _mngr->getComponent<Transform>(pm);
	SDL_Rect playerRect = build_sdlrect(pTR->_pos, pTR->_width, pTR->_height);

	auto &ghosts = _mngr->getEntities(ecs::grp::GHOST);

	for (auto i = 0u; i < ghosts.size(); i++) {
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

	auto& fruits = _mngr->getEntities(ecs::grp::FRUITS);

	for (auto i = 0u; i < fruits.size(); i++) {
		auto fruitTr = _mngr->getComponent<Transform>(fruits[i]);
		SDL_Rect ghostRect = build_sdlrect(fruitTr->_pos, fruitTr->_width, fruitTr->_height);

		SDL_Rect result;
		if (SDL_IntersectRect(&playerRect, &ghostRect, &result)) _mngr->setAlive(fruits[i], false);
	}

	auto& wonderFruits = _mngr->getEntities(ecs::grp::WONDER_FRUITS);

	for (auto i = 0u; i < wonderFruits.size(); i++) {
		auto wonderFruitTr = _mngr->getComponent<Transform>(wonderFruits[i]);
		SDL_Rect ghostRect = build_sdlrect(wonderFruitTr->_pos, wonderFruitTr->_width, wonderFruitTr->_height);

		SDL_Rect result;
		if (SDL_IntersectRect(&playerRect, &ghostRect, &result)) {
			_mngr->setAlive(fruits[i], false);
			Message m;
			m.id = _m_IMMUNITY_START;
			_mngr->send(m);
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