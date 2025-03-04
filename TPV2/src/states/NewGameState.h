#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../facade/FighterUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"

class NewGameState : public GameState{
public:
	NewGameState() {}
	~NewGameState() {}

	Font font = new Font("ARIAL.tff", 8);
	std::string text = "press any key to start a new game";
	auto& inputHandler;

	void enter() {
		inputHandler = *InputHandler::Instance();
	}
	void update() {
		font.renderText(text, SDL_Color::b);

		if (inputHandler.keyDownEvent()) {
			FighterUtils::reset_lives(3);
			Game::Instance()->setState(Game::NEWROUND);
		}
	}
	void leave() {

	}
};
