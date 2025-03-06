#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../facade/FighterUtils.h"
#include "../facade/AsteroidsUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/RandomNumberGenerator.h"

class NewRoundState : public GameState{
public:
	NewRoundState() {}
	~NewRoundState() {}

	Font font = Font("ARIAL.tff", 8);
	std::string text = "press ENTER to start a new game";
	InputHandler* inputHandler;
	FighterUtils _fachadaFighter;
	AsteroidsUtils _fachadaAsteroids;
	RandomNumberGenerator _rnd;

	void enter() {
		inputHandler = InputHandler::Instance();
		_fachadaFighter = FighterUtils();
	}
	void update() {
		font.renderText(text, SDL_Color{ 0, 0, 255, 255 });

		if (inputHandler->isKeyDown(SDLK_KP_ENTER)) {
			_fachadaFighter.reset_fighter();
			_fachadaAsteroids.remove_all_asteroids();
			_fachadaAsteroids.create_asteroids(2, Vector2D {_rnd.nextInt(0, 600), _rnd.nextInt(0, 480) });
			Game::Instance()->setState(Game::RUNNING);
		}
	}
	void leave() {

	}
};
