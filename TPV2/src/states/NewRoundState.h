#pragma once
#include "GameState.h"
#include "../game/Game.h"
#include "../facade/FighterUtils.h"
#include "../facade/AsteroidsUtils.h"
#include "../sdlutils/Font.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/RandomNumberGenerator.h"

class NewRoundState : public GameState{
public:
	NewRoundState() : inputHandler(&ih()), font(&sdlutils().fonts().at("ARIAL16")) {}
	~NewRoundState() {}

	Font font;
	std::string text = "press ENTER to start a new game";
	InputHandler* inputHandler;
	FighterUtils _fachadaFighter;
	AsteroidsUtils _fachadaAsteroids;
	RandomNumberGenerator _rnd;

	void enter();
	void update();
	void leave();
};
