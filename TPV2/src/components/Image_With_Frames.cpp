#include "Image_With_Frames.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"

void Image_With_Frames::initComponent() {
	_tr = _ent->getMngr()->getComponent<Transform>(_ent);
}

void Image_With_Frames::update() {
	timer += sdlutils().deltaTime();

	if (timer >= 0.5f){
		_currentFrame++;
		if (_currentFrame >= _rows * _cols) _currentFrame = 0;
		timer = 0;
	}
}

void Image_With_Frames::render()
{
	SDL_Rect dest = build_sdlrect(_tr->getPos(), _tr->getWidth(),
		_tr->getHeight());

	SDL_Rect source{_currentFrame % _cols, _currentFrame / _rows, _width, _height};

	assert(_tex != nullptr);
	_tex->render(source, dest);
}