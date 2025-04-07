#include "NewRoundState.h"

void NewRoundState::enter() {}

void
NewRoundState::update() {
	_text->render(400,300);

	if (inputHandler->isKeyDown(SDLK_KP_ENTER)) {
		Game::Instance()->send(_message);
		Game::Instance()->setState(Game::RUNNING);
	}
}

void NewRoundState::leave() {}