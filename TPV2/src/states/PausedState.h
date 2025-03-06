#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../facade/FighterUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/VirtualTimer.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/VirtualTimer.h"
#include "../sdlutils/SDLUtils.h"

class PausedState : public GameState{
public:
	PausedState() {}
	~PausedState() {}
	
	Font _font = Font("ARIAL.tff", 8);
	std::string text = "press any key to resume the game";
	InputHandler* inputHandler;

	void enter() {
		sdlutils().virtualTimer().pause();
		inputHandler = InputHandler::Instance();
	}
	void update() {
		_font.renderText(text, SDL_Color{ 0, 0, 255, 255 });

		if (inputHandler->keyDownEvent()) {
			Game::Instance()->setState(Game::RUNNING);
		}
	}
	void leave() {
		sdlutils().virtualTimer().resume();
	}
};
