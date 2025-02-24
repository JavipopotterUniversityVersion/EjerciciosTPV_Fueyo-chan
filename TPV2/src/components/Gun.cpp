#include "Gun.h"

void
Gun::reset() {
	auto it = begin();
	while (it != end()) {
		it.used = false;
		it++;
	}
}

void
Gun::initComponent() { _tr = _ent->getMngr()->getComponent<Transform>(_ent); }

void
Gun::update() {
	auto& inputHandler = *InputHandler::Instance();

	if ((inputHandler.keyDownEvent() && inputHandler.isKeyDown(SDLK_s)) && (sdlutils().virtualTimer().currRealTime() >= _shootTime)) {
		int bw = 5;
		int bh = 20;
		Vector2D c = _tr->getPos() + Vector2D(w / 2.0f, h / 2.0f);
		Vector2D bp = c - Vector2D(bw / 2, h / 2.0f + 5.0f + bh).rotate(_tr->getRotation()) - Vector2D(bw / 2, bh / 2);
		Vector2D bv = Vector2D(0, -1).rotate(_tr->getRotation()) * (_tr->getVelocity().magnitude() + 5.0f);
		float br = Vector2D(0, -1).angle(bv);
		_shootTime += sdlutils().virtualTimer().currRealTime() + 0.25f;
		shoot(bp, bv, bw, bh, br);
	}
}

void
Gun::render() {
	
}

void
Gun::shoot(Vector2D p, Vector2D v, int width, int height, float r) {

}