#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../facade/FighterUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/VirtualTimer.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"

class PausedState : public GameState{
public:
	PausedState() : inputHandler(&ih()), _font(&sdlutils().fonts().at("ARIAL16")) {}
	~PausedState() {}
	
	Font* _font;
	std::string text = "press any key to resume the game";
	InputHandler* inputHandler;

	void enter();
	void update();
	void leave();
};
