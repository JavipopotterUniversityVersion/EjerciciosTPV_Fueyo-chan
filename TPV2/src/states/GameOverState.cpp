#include "GameOverState.h"

void GameOverState::enter() {
	ecs::Manager* manager = Game::Instance()->getManager();
	Message m;
	m.id = _m_GAME_OVER;
	manager->send(m);
}

void
GameOverState::update() {
	_text->render(350,300);

	if (inputHandler->keyDownEvent()) {
		Game::Instance()->setState(Game::NEWGAME);
	}
}

void GameOverState::leave() {}