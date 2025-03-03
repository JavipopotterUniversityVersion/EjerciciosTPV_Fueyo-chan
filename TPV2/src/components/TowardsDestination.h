#pragma once
#include "../sdlutils/SDLUtils.h"
#include "Transform.h"
#include "../ecs/Manager.h"

class TowardsDestination : public ecs::Component {
public:
	Transform* _tr;
	Vector2D _targetPos;
	RandomNumberGenerator _rnd;

	TowardsDestination(float s) { _speed = s; }
	~TowardsDestination();

	void initComponent() {
		_tr = _ent->getMngr()->getComponent<Transform>(_ent);
		_targetPos = {_rnd.nextInt(0, 800), _rnd.nextInt(0, 600)};
	}

	void update() {
		Vector2D newDir = (_targetPos - _tr->getPos());
		if (abs(newDir) <= 10.0f) {
			_targetPos = { _rnd.nextInt(0, 800), _rnd.nextInt(0, 600) };
		}
		newDir.normalize();
		_tr->setVelocity(newDir * _speed);
		_tr->getVelocity().rotate(_tr->getVelocity().angle(_playerTr->getPos() - _tr->getPos()));
	}

private:
	float _speed;
}