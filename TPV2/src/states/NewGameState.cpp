#include "NewGameState.h"

void NewGameState::enter() {}

void
NewGameState::update() {
	//_font->renderText(text, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->keyDownEvent()) {
		Message m;
		m.id = _m_NEW_GAME;
		Game::Instance()->send(m);
		Game::Instance()->setState(Game::NEWROUND);
	}
}

void NewGameState::leave() {}