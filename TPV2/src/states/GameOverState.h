#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../sdlutils/SDLUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"
#include "../systems/PacManSystem.h"
#include "../systems/GhostSystem.h"
#include "../systems/FoodSystem.h"

class GameOverState : public GameState {
public:
	GameOverState() : inputHandler(&ih()), _text(&sdlutils().msgs().at("gameover")) {}
	~GameOverState() {}

	Texture* _text;
	
	FoodSystem* _foodSystem;
	GhostSystem* _ghostSystem;
	PacManSystem* _pacManSystem;

	InputHandler* inputHandler;

	void enter();
	void update();
	void leave();
};
