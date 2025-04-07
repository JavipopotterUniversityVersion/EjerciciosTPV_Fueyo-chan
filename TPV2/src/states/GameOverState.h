#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../sdlutils/SDLUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"

class GameOverState : public GameState {
public:
	GameOverState() : inputHandler(&ih()), _text(&sdlutils().msgs().at("gameover")) {}
	~GameOverState() {}

	Font* _text;
	/*std::string _loseText = "Game Over Loser! Press ENTER to continue.";
	std::string _winText = "Game Over Champion! Press ENTER to continue.";*/
	std::string _usedText;

	InputHandler* inputHandler;

	void enter();
	void update();
	void leave();
};
