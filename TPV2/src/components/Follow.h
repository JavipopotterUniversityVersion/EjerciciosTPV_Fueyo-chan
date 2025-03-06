#pragma once
#include "../sdlutils/SDLUtils.h"
#include "Transform.h"
#include "../ecs/Manager.h"

class Follow : public ecs::Component {
public:
	Transform* _tr;
	Transform* _playerTr;

	Follow(float s) { _speed = s; }
	~Follow() {};

	void initComponent() {
		_tr = _ent->getMngr()->getComponent<Transform>(_ent);
		_playerTr = _ent->getMngr()->getComponent<Transform>(_ent->getMngr()->getEntities(ecs::grp::PLAYER)[0]);
	}

	void update() {
		Vector2D newDir = (_playerTr->getPos() - _tr->getPos());
		newDir.normalize();
		_tr->setVelocity(newDir * _speed);
		_tr->getVelocity().rotate(_tr->getVelocity().angle(_playerTr->getPos() - _tr->getPos()) > 0 ? 1.0f : -1.0f);
	}

	__CMPID_DECL__(ecs::cmp::FOLLOW_TARGET)

private:
	float _speed;
};