#include "NewRoundState.h"

void NewRoundState::enter() {}

void
NewRoundState::update() {
	_text->render(400,300);

	if (inputHandler->isKeyDown(SDLK_KP_ENTER)) {
		Message m;
		m.id = _m_ROUND_START;
		Game::Instance()->getManager()->send(m);
		Game::Instance()->setState(Game::RUNNING);
	}
}

void NewRoundState::leave() {}