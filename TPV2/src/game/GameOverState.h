#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "FighterUtils.h"
#include "../sdlutils/SDLUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"

class GameOverState : public GameState{
public:
	GameOverState() : inputHandler(&ih()), _font(&sdlutils().fonts().at("ARIAL16")) {}
	~GameOverState() {}

	Font* _font;
	std::string _loseText = "Game Over Loser! Press ENTER to continue.";
	std::string _winText = "Game Over Champion! Press ENTER to continue.";
	std::string _usedText;

	InputHandler* inputHandler;

	void enter();
	void update();
	void leave();
};
