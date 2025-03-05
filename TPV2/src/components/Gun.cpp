#include "Gun.h"
#include "../sdlutils/SDLUtils.h"

Gun::Gun()
{
	_bulletTex = &sdlutils().images().at("fire");
}

void
Gun::reset() {
	auto it = begin();
	while (it != end()) {
		it->used = false;
		it++;
	}
}

void
Gun::initComponent() { _tr = _ent->getMngr()->getComponent<Transform>(_ent); }

void
Gun::update() {
	auto& inputHandler = *InputHandler::Instance();
	if (inputHandler.isKeyDown(SDLK_SPACE) && (sdlutils().virtualTimer().currRealTime() >= _shootTime)) {
		int bw = 5;
		int bh = 20;

		Vector2D c = _tr->getPos() + Vector2D(_tr->getWidth() / 2.0f, _tr->getHeight() / 2.0f);
		Vector2D bp = c - Vector2D(bw / 2, _tr->getHeight() / 2.0f + 5.0f + bh).rotate(_tr->getRotation()) - Vector2D(bw / 2, bh / 2);
		Vector2D bv = Vector2D(0, -1).rotate(_tr->getRotation()) * 5;
		float br = Vector2D(0, -1).angle(bv);

		_shootTime = sdlutils().virtualTimer().currRealTime() + SHOOT_RATE;
		shoot(bp, bv, bw, bh, br);
	}
}

void
Gun::render() {
	for (auto it = _bullets.begin(); it < _bullets.end(); it++)
	{
		it->pos = it->pos + it->vel;
		SDL_Rect dest{ it->pos.getX(), it->pos.getY(), it->width, it->height };
		_bulletTex->render(dest, it->rot);
	}
}

void
Gun::shoot(Vector2D p, Vector2D v, int width, int height, float r) {
	auto it = _lastActiveBullet++;
	while (it->used && (it != _lastActiveBullet)) {
		it++;
	}
	if (!it->used) {
		_lastActiveBullet = it;
		if (_lastActiveBullet == _bullets.end() - 1) _lastActiveBullet = _bullets.begin();
		_lastActiveBullet->pos = p;
		_lastActiveBullet->vel = v;
		_lastActiveBullet->width = width;
		_lastActiveBullet->height = height;
		_lastActiveBullet->rot = r;
		_lastActiveBullet->used = true;
	}
}