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

	void enter();
	void update();
	void leave();
};
