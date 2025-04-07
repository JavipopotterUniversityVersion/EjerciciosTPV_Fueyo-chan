#include "RunningState.h"

RunningState::RunningState(){ }

void
RunningState::enter() {
	_collisionSystem = Game::Instance()->getMngr()->getSystem();
	_foodSystem = Game::Instance()->getMngr()->getSystem();
	_GameCtrlSystem = Game::Instance()->getMngr()->getSystem();
	_GhostSystem = Game::Instance()->getMngr()->getSystem();
	_InmunitySystem = Game::Instance()->getMngr()->getSystem();
	_PacManSystem = Game::Instance()->getMngr()->getSystem();
	_RenderSystem = Game::Instance()->getMngr()->getSystem();
	_StarsSystem = Game::Instance()->getMngr()->getSystem();
}

void
RunningState::update() {
	auto& inputHandler = *InputHandler::Instance();

	//Si se pulsa la tecla "p" se pausa el juego
	if (inputHandler.isKeyDown(SDLK_p)) {
		Game::Instance()->setState(Game::PAUSED);
	}

	_collisionSystem->update();
	_foodSystem->update();
	_GameCtrlSystem->update();
	_GhostSystem->update();
	_InmunitySystem->update();
	_PacManSystem->update();
	_RenderSystem->update();
	_StarsSystem->update();

}

void RunningState::leave() {}