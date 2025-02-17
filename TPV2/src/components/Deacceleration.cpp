#include "Deacceleration.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#include "Transform.h"

void Deacceleration::update()
{
	Transform* t = _ent->getMngr()->getComponent<Transform>(_ent);
	t->setVelocity(t->getVelocity().getX() * _slowFactor, t->getVelocity().getY() * _slowFactor);

	if (t->getVelocity().magnitude() <= 0.05f) t->setVelocity(0,0);
}