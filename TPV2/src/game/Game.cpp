// This file is part of the course TPV2@UCM - Samir Genaim

#include "Game.h"

#include "../sdlutils/SDLUtils.h"
#include "../utils/Collisions.h"
#include "../ecs/Entity.h"
#include "../components/Image.h"
#include "../facade/FighterUtils.h"

Game::Game(){
	_manager = new ecs::Manager();
}

Game::~Game() {

	// release SLDUtil if the instance was created correctly.
	if (!SDLUtils::HasInstance())
		SDLUtils::Release();
}

void Game::init() {

	// initialize the SDL singleton
	if (!SDLUtils::Init("ASTEROIDS", 800, 600,
			"resources/config/asteroid.resources.json")) {

		std::cerr << "Something went wrong while initializing SDLUtils"
				<< std::endl;
		return;
	}
}

void Game::start() {

	// a boolean to exit the loop
	bool exit = false;
	SDL_Event event;

	// reset the time before starting - so we calculate correct
	// delta-time in the first iteration
	//
	sdlutils().resetTime();

	while (!exit) {
		// store the current time -- all game objects should use this time when
		// then need to the current time. They also have accessed to the time elapsed
		// between the last two calls to regCurrTime().
		Uint32 startTime = sdlutils().regCurrTime();

		// handle input
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_KEYDOWN
					&& event.key.keysym.scancode == SDL_SCANCODE_ESCAPE) {
				exit = true;
				continue;
			}
		}

		_manager->update();

		sdlutils().clearRenderer();

		_manager->render();

		sdlutils().presentRenderer();
		Uint32 frameTime = sdlutils().currRealTime() - startTime;

		if (frameTime < 20)
			SDL_Delay(20 - frameTime);
	}

}
