#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../game/messages_defs.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"

class NewRoundState : public GameState {
public:
	NewRoundState() : inputHandler(&ih()), _text(&sdlutils().msgs().at("newround")) {}
	~NewRoundState() {}

	Texture* _text;
	
	InputHandler* inputHandler;

	void enter();
	void update();
	void leave();
};
