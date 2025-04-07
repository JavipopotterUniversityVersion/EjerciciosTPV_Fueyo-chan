#include "PauseState.h"

void PausedState::enter() { sdlutils().virtualTimer().pause(); }

void
PausedState::update() {
	_text->render(400,300);

	if (inputHandler->keyDownEvent()) {
		Game::Instance()->setState(Game::RUNNING);
	}
}

void PausedState::leave() { sdlutils().virtualTimer().resume(); }