#include "Image_With_Frames.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#include "../sdlutils/SDLUtils.h"

void Image_With_Frames::initComponent() {
	_img = _ent->getMngr()->getComponent<Image>(_ent);
}

void Image_With_Frames::update() {
	timer += sdlutils().deltaTime();

	if (timer >= 0.5f)
	{
		Texture* tex = _textures.front();
		_textures.pop();
		_textures.push(tex);
		_img->setTexture(tex);
	}
}