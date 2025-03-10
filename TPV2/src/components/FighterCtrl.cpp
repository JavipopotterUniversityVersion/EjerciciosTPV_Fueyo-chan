#include "FighterCtrl.h"
#include "../sdlutils/InputHandler.h"
#include "Transform.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"
#include "../game/Game.h"

void FighterCrtl::update()
{
	auto& inputHandler = ih();

	if (inputHandler.isKeyDown(SDLK_LEFT))
	{
		t->addRotation(-ROTATION_SPEED);
	}
	else if (inputHandler.isKeyDown(SDLK_RIGHT))
	{
		t->addRotation(ROTATION_SPEED);
	}

	if (inputHandler.isKeyDown(SDLK_UP))
	{
		sdlutils().soundEffects().at("thrust").play();
		t->setVelocity(t->up() * SPEED);
	}
}

void FighterCrtl::initComponent() { t = Game::Instance()->getManager()->getComponent<Transform>(_ent); }