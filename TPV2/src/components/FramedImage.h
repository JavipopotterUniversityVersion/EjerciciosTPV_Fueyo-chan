// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"

class Texture;

struct FramedImage: public ecs::Component {

	FramedImage() :
			_tex() {
	}

	FramedImage(Texture *tex) :
			_tex(tex) {
	}

	virtual ~FramedImage() {
	}

	Texture *_tex;

	Vector2D _start;
	Vector2D _end;

	int frame;
};

