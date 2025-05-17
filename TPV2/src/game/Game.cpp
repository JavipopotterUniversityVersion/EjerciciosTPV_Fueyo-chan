// This file is part of the course TPV2@UCM - Samir Genaim

#include "Game.h"

#include "../ecs/Manager.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../utils/Vector2D.h"
#include "../utils/Collisions.h"

//Include systems
#include "../systems/CollisionsSystem.h"
#include "../systems/GameCtrlSystem.h"
#include "../systems/PacManSystem.h"
#include "../systems/RenderSystem.h"
#include "../systems/GhostSystem.h"
#include "../systems/FoodSystem.h"

//Include game states
#include "../states/GameOverState.h"
#include "../states/NewGameState.h"
#include "../states/NewRoundState.h"
#include "../states/PauseState.h"
#include "../states/RunningState.h"

using ecs::Manager;

Game::Game() :
		_mngr(), //
		_pacmanSys(), //
		_renderSys(), //
		_collisionSys(),
		_ghostSystem()
{}

Game::~Game() {
	delete _mngr;

	// release InputHandler if the instance was created correctly.
	if (InputHandler::HasInstance())
		InputHandler::Release();

	// release SLDUtil if the instance was created correctly.
	if (SDLUtils::HasInstance())
		SDLUtils::Release();

	delete _gameover_state;
	delete _newgame_state;
	delete _paused_state;
	delete _runing_state;
	delete _newround_state;
}

void Game::initGame() {
	//Create the manager
	_mngr = new ecs::Manager();

	//Create the game states
	_gameover_state = new GameOverState();
	_newgame_state = new NewGameState();
	_newround_state = new NewRoundState();
	_paused_state = new PausedState();
	_runing_state = new RunningState();

	//Create the systems
	_pacmanSys = _mngr->addSystem<PacManSystem>();
	_renderSys = _mngr->addSystem<RenderSystem>();
	_collisionSys = _mngr->addSystem<CollisionsSystem>();
	_ghostSystem = _mngr->addSystem<GhostSystem>();
	_foodSystem = _mngr->addSystem<FoodSystem>();
	_inmunitySystem = _mngr->addSystem<InmunitySystem>();

}

bool Game::init() {

	// initialize the SDL singleton
	if (!SDLUtils::Init("PacMan, Stars, ...", 800, 600,
			"resources/config/resources.json")) {

		std::cerr << "Something went wrong while initializing SDLUtils"
				<< std::endl;
		return false;
	}

	// initialize the InputHandler singleton
	if (!InputHandler::Init()) {
		std::cerr << "Something went wrong while initializing SDLHandler"
				<< std::endl;
		return false;
	}

	return true;
}

void Game::start() {

	// a boolean to exit the loop
	bool exit = false;

	auto &ihdlr = ih();

	//We set the first state
	setState(NEWGAME);

	while (!exit) {
		Uint32 startTime = sdlutils().currRealTime();
		sdlutils().regCurrTime();

		// refresh the input handler
		ihdlr.refresh();

		if (ihdlr.isKeyDown(SDL_SCANCODE_ESCAPE)) {
			exit = true;
			continue;
		}

		sdlutils().clearRenderer();
		_current_state->update();
		sdlutils().presentRenderer();

		Uint32 frameTime = sdlutils().currRealTime() - startTime;

		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}

}

