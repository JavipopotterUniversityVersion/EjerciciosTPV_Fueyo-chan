#include "NewRoundState.h"

void NewRoundState::enter() {
	//_foodSystem = Game::Instance()->getManager()->getSystem<FoodSystem>();
	_ghostSystem = Game::Instance()->getManager()->getSystem<GhostSystem>();
	_pacManSystem = Game::Instance()->getManager()->getSystem<PacManSystem>();

	//_foodSystem->restartSystem();
	_ghostSystem->restartSystem();
	_pacManSystem->restartSystem();
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