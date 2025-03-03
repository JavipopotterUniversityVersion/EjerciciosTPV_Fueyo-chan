#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../facade/FighterUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"

class NewRoundState : public GameState{
public:
	NewRoundState() {}
	~NewRoundState() {}

	Font font = new Font("ARIAL.tff", 8);
	std::string text = "press ENTER to start a new game";
	auto& inputHandler;

	void enter() {
		inputHandler = *InputHandler::Instance();
	}
	void update() {
		font.renderText(text, SDL_Color::b);

		if (inputHandler.isKeyDown(SDLK_KP_ENTER)) {
			FighterUtils::reset_fighter();
			AsteroidUtils::remove_all_asteroids();
			AsteroidUtils::create_asteroids(10);
			Game::Instance()->setState(Game::RUNNING);
		}
	}
	void leave() {

	}
};
