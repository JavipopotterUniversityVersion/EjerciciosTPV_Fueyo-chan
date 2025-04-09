#include "GameOverState.h"

void GameOverState::enter() {
	_foodSystem = Game::Instance()->getManager()->getSystem<FoodSystem>();
	_ghostSystem = Game::Instance()->getManager()->getSystem<GhostSystem>();
	_pacManSystem = Game::Instance()->getManager()->getSystem<PacManSystem>();

	_foodSystem->restartSystem();
	_ghostSystem->restartSystem();
	_pacManSystem->restartSystem();
}

void
GameOverState::update() {
	_text->render(350,300);

	if (inputHandler->keyDownEvent()) {
		Game::Instance()->setState(Game::NEWGAME);
	}
}

void GameOverState::leave() {}