// This file is part of the course TPV2@UCM - Samir Genaim

#include "RenderSystem.h"

#include "../game/Game.h"
#include "../components/Image.h"
#include "../components/FramedImage.h"
#include "../components/Transform.h"
#include "../components/Health.h"
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
	drawHearts();
	drawGroup(ecs::grp::GHOST);
	drawGroup(ecs::grp::FRUITS);
	drawGroup(ecs::grp::WONDER_FRUITS);

	_currentFrameStep++;
	if (_currentFrameStep > FRAME_SPACE) _currentFrameStep = 0;
}

void RenderSystem::drawPacMan() {
	auto e = _mngr->getHandler(ecs::hdlr::PACMAN);
	auto tr = _mngr->getComponent<Transform>(e);
	auto framedImage = _mngr->getComponent<FramedImage>(e);

	draw(tr, framedImage);
}


void RenderSystem::drawGroup(ecs::grp::grpId id) {
	auto group = _mngr->getEntities(id);

	for(auto elem : group)
	{
		auto tr = _mngr->getComponent<Transform>(elem);
		auto framedImage = _mngr->getComponent<FramedImage>(elem);

		draw(tr, framedImage);
	}
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

void RenderSystem::draw(Transform* tr, FramedImage* framedImage) {
	SDL_Rect dest = build_sdlrect(tr->_pos, tr->_width, tr->_height);

	Vector2D framePos = Vector2D(framedImage->frame % 8, framedImage->frame / 8);
	framePos = framePos * 128;
	SDL_Rect source = build_sdlrect(framePos, 128, 128);

	assert(framedImage->_tex != nullptr);
	framedImage->_tex->render(source, dest, tr->_rot);

	if(_currentFrameStep == FRAME_SPACE) framedImage->frame++;
	if (framedImage->frame > framedImage->getFrameRange().getY()) framedImage->frame = framedImage->getFrameRange().getX();

}

void RenderSystem::drawHearts() {
	for (int c = 0; c < Game::Instance()->getManager()->getComponent<Health>(
		Game::Instance()->getManager()->getEntities(ecs::hdlr::PACMAN)[0])->GetHealth(); c++)
	{
		SDL_Rect rect{ (c * HEART_SIZE), 0, HEART_SIZE, HEART_SIZE};
		_heartTex->render(rect);
	}
}