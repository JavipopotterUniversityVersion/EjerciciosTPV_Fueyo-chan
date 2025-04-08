// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include "../ecs/Component.h"
#include "../utils/Vector2D.h"
#include "../sdlutils/SDLUtils.h"

class Texture;

struct FramedImage: public ecs::Component {

	FramedImage(const Vector2D& range, Texture* tex = &sdlutils().images().at("sprites")) :
			_tex(tex), _frameRange(range), frame(range.getX()){
	}

	virtual ~FramedImage() {
	}

	Texture *_tex;

	int frame;

	inline const Vector2D& getFrameRange() { return _frameRange; };
	const void setFrameRange(const Vector2D& range) 
	{ 
		frame = range.getX();
		_frameRange = range; 
	}

private:
	Vector2D _frameRange;
};

