#include "NewRoundState.h"

void NewRoundState::enter() {}

void
NewRoundState::update() {
	//_text->renderText(text, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->isKeyDown(SDLK_KP_ENTER)) {
		Game::Instance()->send(_message);
		Game::Instance()->setState(Game::RUNNING);
	}
}

void NewRoundState::leave() {}