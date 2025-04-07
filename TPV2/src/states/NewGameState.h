#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../game/messages_defs.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/SDLUtils.h"
#include "../sdlutils/InputHandler.h"

class NewGameState : public GameState {
public:
	NewGameState() : _text(&sdlutils().msgs().at("newgame")), inputHandler(&ih()) {}
	~NewGameState() {}

	Font* _text;

	Message _message = _m_NEW_GAME;
	InputHandler* inputHandler;

	void enter();
	void update();
	void leave();
};
