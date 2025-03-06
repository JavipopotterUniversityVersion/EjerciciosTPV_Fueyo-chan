#include "GameOverState.h"

void
GameOverState::enter() {

	if (Game::Instance()->getManager()->getEntities(ecs::grp::ASTEROID).size() <= 0) {
		_usedText = _loseText;
	}
	else {
		_usedText = _winText;
	}
}

void
GameOverState::update() {
	_font->renderText(_usedText, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->isKeyDown(SDLK_KP_ENTER)) {
		Game::Instance()->setState(Game::RUNNING);
	}
}

void 
GameOverState::leave(){}