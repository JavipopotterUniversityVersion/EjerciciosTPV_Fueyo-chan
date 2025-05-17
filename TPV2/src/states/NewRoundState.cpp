#include "NewRoundState.h"

void NewRoundState::enter() {
	ecs::Manager* manager = Game::Instance()->getManager();
	Message m;
	m.id = _m_ROUND_START;
	manager->send(m);
}

void
NewRoundState::update() {
	_text->render(250,300);

	if (inputHandler->isKeyDown(SDLK_RETURN)) {
		Message m;
		m.id = _m_ROUND_START;
		Game::Instance()->getManager()->send(m);
		Game::Instance()->setState(Game::RUNNING);
	}
}

void NewRoundState::leave() {}