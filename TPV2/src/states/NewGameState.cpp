#include "NewGameState.h"

void
NewGameState::enter() {
	Game::Instance()->getManager()->getComponent<Health>(
		Game::Instance()->getManager()->getEntities(ecs::hdlr::PACMAN)[0])->ResetHealth();
}

void
NewGameState::update() {
	_text->render(400,300);

	if (inputHandler->keyDownEvent()) {
		Message m;
		m.id = _m_NEW_GAME;
		Game::Instance()->getManager()->send(m);
		Game::Instance()->setState(Game::NEWROUND);
	}
}

void NewGameState::leave() {}