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

	Font _font = Font("ARIAL.tff", 8);
	std::string text = "press any key to start a new game";
	InputHandler* inputHandler;
	FighterUtils _fachadaFighter;

	void enter() {
		inputHandler = InputHandler::Instance();
		_fachadaFighter = FighterUtils();
	}
	void update() {
		_font.renderText(text, SDL_Color{ 0, 0, 255, 255 });

		if (inputHandler->keyDownEvent()) {
			_fachadaFighter.reset_lives();
			Game::Instance()->setState(Game::NEWROUND);
		}
	}
	void leave() {

	}
};
