#include "NewGameState.h"

void NewGameState::enter() {}

void
NewGameState::update() {
	_text->render(400,300);

	if (inputHandler->keyDownEvent()) {
		Message m;
		m.id = _m_NEW_GAME;
		Game::Instance()->send(m);
		Game::Instance()->setState(Game::NEWROUND);
	}
}

void NewGameState::leave() {}