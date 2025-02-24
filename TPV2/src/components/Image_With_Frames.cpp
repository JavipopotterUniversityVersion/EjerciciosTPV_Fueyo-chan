#include "Image_With_Frames.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"

void Image_With_Frames::initComponent() {
	_img = _ent->getMngr()->getComponent<Image>(_ent);
}

void Image_With_Frames::update() {
	//_img->setTexture();
}