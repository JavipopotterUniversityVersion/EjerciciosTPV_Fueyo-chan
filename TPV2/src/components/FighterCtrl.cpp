#include "FighterCtrl.h"
#include "../sdlutils/InputHandler.h"
#include "Transform.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"

void FighterCrtl::update()
{
	auto& inputHandler = *InputHandler::Instance();

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
		t->setVelocity(t->up() * SPEED);
	}
}

void FighterCrtl::initComponent() { t = _ent->getMngr()->getComponent<Transform>(_ent); }