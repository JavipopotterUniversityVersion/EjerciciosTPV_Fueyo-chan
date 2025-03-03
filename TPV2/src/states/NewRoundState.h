#pragma once
#include "GameState.h"
#include "../facade/FighterUtils.h"
#include "../sdlutils/Font.h"

class NewRoundState : public GameState{
public:
	NewRoundState() {}
	~NewRoundState() {}

	Font font = new Font("ARIAL.tff", 8);
	std::string text = "press ENTER to start a new game";

	void enter() {

	}
	void update() {
		font.renderText(text, SDL_Color::b);
		
		if (SDL_KEYDOWN) {
			Game::Instance->setState(Game::NEWROUND);
		}
	}
	void leave() {

	}
};
