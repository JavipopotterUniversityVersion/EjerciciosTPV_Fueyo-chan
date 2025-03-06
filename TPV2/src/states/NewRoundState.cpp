#include "NewRoundState.h"

void
NewRoundState::enter() {
	inputHandler = InputHandler::Instance();
	_fachadaFighter = FighterUtils();
}

void
NewRoundState::update() {
	font->renderText(text, SDL_Color{ 0, 0, 255, 255 });

	if (inputHandler->isKeyDown(SDLK_KP_ENTER)) {
		std::cout << "skibidi" << std::endl;
		_fachadaFighter.create_fighter();
		_fachadaFighter.reset_fighter();
		_fachadaAsteroids.remove_all_asteroids();
		_fachadaAsteroids.create_asteroids(2, Vector2D{ float(_rnd.nextInt(0, 600)), float(_rnd.nextInt(0, 480)) });
		Game::Instance()->setState(Game::RUNNING);
	}
}

void
NewRoundState::leave() {}