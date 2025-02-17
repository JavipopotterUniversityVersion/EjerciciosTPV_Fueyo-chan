#include "FighterCtrl.h"
#include "../sdlutils/InputHandler.h"
#include "Transform.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"

void FighterCrtl::update()
{
	auto& inputHandler = *InputHandler::Instance();
	Transform* t = _ent->getMngr()->getComponent<Transform>(_ent);

	if (inputHandler.isKeyDown(SDLK_LEFT))
	{
		
	}
}