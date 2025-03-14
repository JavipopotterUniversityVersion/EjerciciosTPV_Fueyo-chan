// This file is part of the course TPV2@UCM - Samir Genaim

#include "Game.h"

#include "../sdlutils/SDLUtils.h"
#include "../utils/Collisions.h"
#include "../ecs/Entity.h"
#include "../components/Image.h"
#include "FighterUtils.h"
#include "../game/AsteroidsUtils.h"
#include "../sdlutils/InputHandler.h"
#include "../game/GameOverState.h"
#include "../game/NewGameState.h"
#include "../game/NewRoundState.h"
#include "../game/PausedState.h"
#include "../game/RunningState.h"

Game::Game(){
}

Game::~Game() {

	// release SLDUtil if the instance was created correctly.
	if (!SDLUtils::HasInstance())
		SDLUtils::Release();
}

void Game::initGame() {
	_manager = new ecs::Manager();

	FighterUtils fUtils;
	fUtils.create_fighter();

	_gameover_state = new GameOverState();
	_newgame_state = new NewGameState();
	_newround_state = new NewRoundState();
	_paused_state = new PausedState();
	_runing_state = new RunningState();

}
bool Game::init() {

	// initialize the SDL singleton
	if (!SDLUtils::Init("ASTEROIDS", 800, 600,
			"resources/config/asteroid.resources.json")) {

		std::cerr << "Something went wrong while initializing SDLUtils"
				<< std::endl;
		return false;
	}

	if (!InputHandler::Init()) {
		std::cerr << "Something went wrong while initializing InputHandler"
			<< std::endl;
		return false;
	}

	return true;
}

void Game::start() {

	bool exit = false;
	auto& _inputHandler = ih();
	auto& vt = sdlutils().virtualTimer(); 

	vt.resetTime();
	setState(NEWGAME);
	while (!exit) {
		Uint32 startTime = vt.regCurrTime();
		_inputHandler.refresh();
		if (_inputHandler.isKeyDown(SDL_SCANCODE_ESCAPE)) {
			exit = true;
			continue;
		}

		sdlutils().clearRenderer();
		_current_state->update();
		sdlutils().presentRenderer();

		Uint32 frameTime = sdlutils().currRealTime() - startTime;


		if (frameTime < 10) SDL_Delay(10 - frameTime);
	}

}
