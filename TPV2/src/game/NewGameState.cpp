#include "NewGameState.h"
#include "FighterUtils.h"

void
NewGameState::enter() {
	inputHandler = InputHandler::Instance();
}

void
NewGameState::update() {
	_font->renderText(text, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->keyDownEvent()) {
		FighterUtils fUtils;
		fUtils.reset_lives();

		Game::Instance()->setState(Game::NEWROUND);
	}
}

void
NewGameState::leave(){}