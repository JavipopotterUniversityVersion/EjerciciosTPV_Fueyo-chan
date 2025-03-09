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
	~TowardsDestination() {};

	void initComponent() {
		_tr = _ent->getMngr()->getComponent<Transform>(_ent);
		_targetPos = { float(_rnd.nextInt(0, 600)), float(_rnd.nextInt(0, 480)) };
	}

	void update() {
		Vector2D newDir = (_targetPos - _tr->getPos());
		if (abs(newDir.magnitude()) <= 10.0f) {
			_targetPos = {float( _rnd.nextInt(0, 600)), float(_rnd.nextInt(0, 480)) };
		}
		newDir = newDir.normalize();
		_tr->setVelocity(newDir * _speed);
		_tr->getVelocity().rotate(_tr->getVelocity().angle(_targetPos - _tr->getPos()));
	}

	void forceDirection(Vector2D _newTargetPos) {
		_targetPos = _newTargetPos;
	}

	__CMPID_DECL__(ecs::cmp::TOWARDS_DESTINATION)
private:
	float _speed;
};