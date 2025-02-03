#include "FighterCtrl.h"
#include "../sdlutils/InputHandler.h"
#include "Container.h"

void FighterCtrl::handleInput(Container* o)
{
	if (ih().isKeyDown(SDLK_LEFT))
	{
		o->setRotation(o->getRotation() - 5.0f);
	}

	if (ih().isKeyDown(SDLK_RIGHT))
	{
		o->setRotation(o->getRotation() + 5.0f);
	}
}