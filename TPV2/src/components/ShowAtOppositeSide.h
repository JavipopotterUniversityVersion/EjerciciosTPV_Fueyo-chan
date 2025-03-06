#pragma once
#include "../ecs/Component.h"
#include "../components/Transform.h"
#include "../sdlutils/SDLUtils.h"
#include "../game/Game.h"
#include "../ecs/Manager.h"

class ShowAtOppositeSide : public ecs::Component
{
public:
	Transform* _tr;

	ShowAtOppositeSide() {};
	~ShowAtOppositeSide() {};

	void initComponent() {
		_tr = Game::Instance()->getManager()->getComponent<Transform>(_ent);
	}
	void update() override {
		if (_tr->x() < 0) {
			_tr->set(sdlutils().width(), _tr->y());
		}
		else if (_tr->x() > sdlutils().width()) {
			_tr->set(0, _tr->y());
		}
		if (_tr->y() < 0) {
			_tr->set(_tr->x(), sdlutils().height());
		}
		else if (_tr->y() > sdlutils().height()) {
			_tr->set(_tr->x(), 0);
		}
	}

	__CMPID_DECL__(ecs::cmp::SHOW_AT_OPPOSITE_SIDE)
};