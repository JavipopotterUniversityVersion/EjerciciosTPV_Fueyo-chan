// This file is part of the course TPV2@UCM - Samir Genaim

#include "RenderSystem.h"

#include "../components/Image.h"
#include "../components/Transform.h"
#include "../ecs/Manager.h"
#include "../sdlutils/macros.h"
#include "../sdlutils/SDLUtils.h"
#include "../sdlutils/Texture.h"
#include "GameCtrlSystem.h"

RenderSystem::RenderSystem() {

}

RenderSystem::~RenderSystem() {
}

void RenderSystem::initSystem() {
}

void RenderSystem::update() {
	drawMsgs();
	drawPacMan();
	drawGhosts();
}

void RenderSystem::drawPacMan() {
	auto e = _mngr->getHandler(ecs::hdlr::PACMAN);
	auto tr = _mngr->getComponent<Transform>(e);
	auto tex = _mngr->getComponent<Image>(e)->_tex;
	draw(tr, tex);
}


void RenderSystem::drawGhosts() {
	auto e = _mngr->getHandler(ecs::hdlr::GHOST);
	auto tr = _mngr->getComponent<Transform>(e);
	auto tex = _mngr->getComponent<Image>(e)->_tex;
	draw(tr, tex);
}


void RenderSystem::drawMsgs() {
	// draw the score
	//
	//Texture scoreTex(sdlutils().renderer(), std::to_string(score),
	//		sdlutils().fonts().at("ARIAL24"), build_sdlcolor(0x444444ff));

	//SDL_Rect dest = build_sdlrect( //
	//		(sdlutils().width() - scoreTex.width()) / 2.0f, //
	//		10.0f, //
	//		scoreTex.width(), //
	//		scoreTex.height());

	//scoreTex.render(dest);

	// draw add stars message
}

void RenderSystem::draw(Transform *tr, Texture *tex) {
	SDL_Rect dest = build_sdlrect(tr->_pos, tr->_width, tr->_height);

	assert(tex != nullptr);
	tex->render(dest, tr->_rot);
}
