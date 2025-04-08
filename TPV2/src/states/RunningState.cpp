#include "RunningState.h"

RunningState::RunningState(){ }

void
RunningState::enter() {
	_collisionSystem = Game::Instance()->getManager()->getSystem<CollisionsSystem>();
	_foodSystem = Game::Instance()->getManager()->getSystem<FoodSystem>();
	_ghostSystem = Game::Instance()->getManager()->getSystem<GhostSystem>();
	_inmunitySystem = Game::Instance()->getManager()->getSystem<InmunitySystem>();
	_pacManSystem = Game::Instance()->getManager()->getSystem<PacManSystem>();
	_renderSystem = Game::Instance()->getManager()->getSystem<RenderSystem>();

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
	_ghostSystem->update();
	_inmunitySystem->update();
	_pacManSystem->update();
	_renderSystem->update();

	Game::Instance()->getManager()->refresh();
}

void RunningState::leave() {}