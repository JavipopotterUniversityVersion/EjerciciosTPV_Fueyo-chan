#pragma once
#include "../ecs/Component.h"
#include "Transform.h"
#include "../sdlutils/SDLUtils.h"

class ShowAtOppositeSide : public ecs::Component
{
public:
	ShowAtOppositeSide();
	~ShowAtOppositeSide();

	void update() override {
		tp(_tr);
	}

	void tp() {
		Transform* _tr = _ent->getComponent
		if (_tr->x() < 0) {
			_tr->Set(SDLUtils::width(), _tr->y());
		}
		else if (_tr->x() > SDLUtils::width()) {
			_tr->Set(0, _tr->y());
		}
		if (_tr->y() < 0) {
			_tr->Set(_tr->x(), SDLUtils::height());
		}
		else if (_tr->y() > SDLUtils::height()) {
			_tr->Set(_tr->x(), 0);
		}
	}
};