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

	void enter() {

		if (Game::Instance()->getManager()->getEntities(ecs::grp::ASTEROID).size() <= 0) {
			_usedText = _loseText;
		} else {
			_usedText = _winText;
		}
	}
	void update() {
		_font.renderText(_usedText, SDL_Color{ 0, 0, 255, 255 });

		if (inputHandler->isKeyDown(SDLK_KP_ENTER)) {
			Game::Instance()->setState(Game::RUNNING);
		}
	}
	void leave() {

	}
};
