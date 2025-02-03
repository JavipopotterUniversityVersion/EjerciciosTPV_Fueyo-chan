// This file is part of the course TPV2@UCM - Samir Genaim

#include "Game.h"

#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../utils/Collisions.h"

#include "Container.h"
#include "GameManager.h"
#include "AIPaddle.h"
#include "BounceOnBorder.h"
#include "EmptyRectangleRenderer.h"
#include "GameCtrl.h"
#include "ImageRenderer.h"
#include "InfoMsgs.h"
#include "MovePaddleWithKeyBoard.h"
#include "MovePaddleWithMouse.h"
#include "RectangleRenderer.h"
#include "ScoreRenderer.h"
#include "SimpleMove.h"
#include "StopOnBorder.h"

Game::Game(){}

Game::~Game() {
	// delete all game objects
	for (GameObject *o : _objs) {
		delete o;
	}

	// release InputHandler if the instance was created correctly.
	if (InputHandler::HasInstance())
		InputHandler::Release();

	// release SLDUtil if the instance was created correctly.
	if (SDLUtils::HasInstance())
		SDLUtils::Release();
}

void Game::init() {

	// initialize the SDL singleton
	if (!SDLUtils::Init("Ping Pong", 800, 600,
			"resources/config/test.resources.json")) {

		std::cerr << "Something went wrong while initializing SDLUtils"
				<< std::endl;
		return;
	}

	// initialize the InputHandler singleton
	if (!InputHandler::Init()) {
		std::cerr << "Something went wrong while initializing SDLHandler"
				<< std::endl;
		return;

	}

	_fighter = new Container();
	_fighter->getPos().setX(sdlutils().width() / 2);
	_fighter->getPos().setY(sdlutils().height() / 2);
	_fighter->setHeight(50);
	_fighter->setHeight(50);

	ImageRenderer* spriteRenderer = new ImageRenderer(&sdlutils().images().at("Fighter"));
	_fighter->setRotation(90);
	_fighter->addComponent(spriteRenderer);

	_objs.push_back(_fighter);
}

void Game::start() {

	// a boolean to exit the loop
	bool exit = false;

	auto &ihdlr = ih();

	while (!exit) {

		// store the current time -- all game objects should use this time when
		// then need to the current time. They also have accessed to the time elapsed
		// between the last two calls to regCurrTime().
		Uint32 startTime = sdlutils().currRealTime();

		// refresh the input handler
		ihdlr.refresh();

		if (ihdlr.isKeyDown(SDL_SCANCODE_ESCAPE)) {
			exit = true;
			continue;
		}

		for (auto &o : _objs) {
			o->handleInput();
		}

		// update
		for (auto &o : _objs) {
			o->update();
		}

		sdlutils().clearRenderer();

		// render
		for (auto &o : _objs) {
			o->render();
		}

		sdlutils().presentRenderer();
		Uint32 frameTime = sdlutils().currRealTime() - startTime;

		if (frameTime < 20)
			SDL_Delay(20 - frameTime);
	}

}