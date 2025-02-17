#include "Deacceleration.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#include "Transform.h"

void Deacceleration::update()
{
	Transform* t = _ent->getMngr()->getComponent<Transform>(_ent);
	t->SetVelocity(t->getVelocity().getX() * _slowFactor, t->getVelocity().getY() * _slowFactor);
}