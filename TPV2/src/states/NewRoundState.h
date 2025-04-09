#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../game/messages_defs.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../systems/PacManSystem.h"
#include "../systems/GhostSystem.h"
#include "../systems/FoodSystem.h"

class NewRoundState : public GameState {
public:
	NewRoundState() : inputHandler(&ih()), _text(&sdlutils().msgs().at("newround")) {}
	~NewRoundState() {}

	Texture* _text;
	
	InputHandler* inputHandler;

	FoodSystem* _foodSystem;
	GhostSystem* _ghostSystem;
	PacManSystem* _pacManSystem;

	void enter();
	void update();
	void leave();
};
