#include "Deacceleration.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#include <iostream>

void Deacceleration::update()
{
	t->multVelocity(_slowFactor);
	if (t->getVelocity().magnitude() <= 0.05f) t->setVelocity(0,0);
}

void Deacceleration::initComponent()
{
	t = _ent->getMngr()->getComponent<Transform>(_ent);
}