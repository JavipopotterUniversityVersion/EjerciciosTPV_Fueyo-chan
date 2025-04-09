#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../game/messages_defs.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/SDLUtils.h"
#include "../sdlutils/InputHandler.h"
#include "../components/Health.h"

class NewGameState : public GameState {
public:
	NewGameState() : _text(&sdlutils().msgs().at("newgame")), inputHandler(&ih()) {}
	~NewGameState() {}

	Texture* _text;
	InputHandler* inputHandler;

	void enter();
	void update();
	void leave();
};
