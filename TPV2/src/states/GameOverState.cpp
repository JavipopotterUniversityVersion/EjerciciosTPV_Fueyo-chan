#include "GameOverState.h"

void GameOverState::enter() {}

void
GameOverState::update() {
	_text->render(400,300);

	if (inputHandler->keyDownEvent()) {
		Game::Instance()->setState(Game::NEWGAME);
	}
}

void GameOverState::leave() {}