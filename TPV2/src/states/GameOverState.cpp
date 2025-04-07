#include "GameOverState.h"

void GameOverState::enter() {}

void
GameOverState::update() {
	_text->renderText(_usedText, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->keyDownEvent()) {
		Game::Instance()->setState(Game::NEWGAME);
	}
}

void GameOverState::leave() {}