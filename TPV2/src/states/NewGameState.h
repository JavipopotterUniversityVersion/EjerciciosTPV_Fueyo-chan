#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../facade/FighterUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/SDLUtils.h"
#include "../sdlutils/InputHandler.h"

class NewGameState : public GameState{
public:
	NewGameState() : _font(&sdlutils().fonts().at("ARIAL16")), inputHandler(&ih()) {}
	~NewGameState() {}
	
	Font* _font;
	std::string text = "press any key to start a new game";
	InputHandler* inputHandler;
	FighterUtils _fachadaFighter;

	void enter();
	void update();
	void leave();
};
