#include "NewRoundState.h"
#include "../ecs/Manager.h"

void
NewRoundState::enter() {
	inputHandler = InputHandler::Instance();
	_fachadaFighter = FighterUtils();
	_fachadaAsteroids = AsteroidsUtils();
}

void
NewRoundState::update() {
	font->renderText(text, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->isKeyDown(SDLK_KP_ENTER)) {
		_fachadaFighter.reset_fighter();
		_fachadaAsteroids.remove_all_asteroids();

		_fachadaAsteroids.create_asteroids(10);

		Game::Instance()->setState(Game::RUNNING);
	}
}

void
NewRoundState::leave() {}