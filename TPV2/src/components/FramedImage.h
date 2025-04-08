// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "../sdlutils/SDLUtils.h"

class Texture;

struct FramedImage: public ecs::Component {

	FramedImage(Vector2D range, Texture* tex = &sdlutils().images().at("sprites")) :
			_tex(tex), _frameRange(range), frame(range.getX()){
	}

	virtual ~FramedImage() {
	}

	Texture *_tex;

	Vector2D _frameRange;

	int frame;
};

