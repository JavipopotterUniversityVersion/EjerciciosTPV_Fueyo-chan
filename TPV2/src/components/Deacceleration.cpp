#include "Deacceleration.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"

void Deacceleration::update()
{
	t->setVelocity(t->getVelocity().getX() * _slowFactor, t->getVelocity().getY() * _slowFactor);

	if (t->getVelocity().magnitude() <= 0.05f) t->setVelocity(0,0);
}

void Deacceleration::initComponent()
{
	Transform* t = _ent->getMngr()->getComponent<Transform>(_ent);
}