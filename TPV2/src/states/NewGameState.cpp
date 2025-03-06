#include "NewGameState.h"

void
NewGameState::enter() {
	inputHandler = InputHandler::Instance();
}

void
NewGameState::update() {
	_font->renderText(text, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->keyDownEvent()) {
		Game::Instance()->setState(Game::NEWROUND);
	}
}

void
NewGameState::leave(){}