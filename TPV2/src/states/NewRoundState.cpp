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
	Game::Instance()->getManager()->render();

	if (inputHandler->isKeyDown(SDLK_KP_ENTER)) {
		_fachadaFighter.reset_fighter();
		_fachadaAsteroids.remove_all_asteroids();

		_fachadaAsteroids.create_asteroids(2, Vector2D{ float(_rnd.nextInt(0, 600)), float(_rnd.nextInt(0, 480)) });

		Game::Instance()->setState(Game::RUNNING);
	}
}

void
NewRoundState::leave() {}