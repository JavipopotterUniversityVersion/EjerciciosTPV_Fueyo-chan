#include "NewGameState.h"

void
NewGameState::enter() {
	inputHandler = InputHandler::Instance();
	_fachadaFighter = FighterUtils();
}

void
NewGameState::update() {
	_font.renderText(text, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->keyDownEvent()) {
		_fachadaFighter.reset_lives();
		Game::Instance()->setState(Game::NEWROUND);
	}
}

void
NewGameState::leave(){}