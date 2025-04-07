#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"

class PausedState : public GameState {
public:
	PausedState() : inputHandler(&ih()), _text(&sdlutils().msgs().at("paused")) {}
	~PausedState() {}

	Texture* _text;
	InputHandler* inputHandler;

	void enter();
	void update();
	void leave();
};
