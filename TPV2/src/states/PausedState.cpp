#include "PausedState.h"

void
PausedState::enter() {
	sdlutils().virtualTimer().pause();
	inputHandler = InputHandler::Instance();
}

void
PausedState::update() {
	_font.renderText(text, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->keyDownEvent()) {
		Game::Instance()->setState(Game::RUNNING);
	}
}

void
PausedState::leave() {
	sdlutils().virtualTimer().resume();
}