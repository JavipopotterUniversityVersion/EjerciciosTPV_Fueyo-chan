#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../facade/FighterUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"

class GameOverState : public GameState{
public:
	GameOverState() {}
	~GameOverState() {}

	Font _font = Font("ARIAL.tff", 8);
	std::string _winText = "Game Over Loser! Press ENTER to continue.";
	std::string _loseText = "Game Over Champion! Press ENTER to continue.";
	std::string _usedText;

	InputHandler* inputHandler;

	void enter();
	void update();
	void leave();
};
