#pragma once
#include "../sdlutils/Texture.h"
#include "../components/Transform.h"

class Image_With_Frames : public ecs::Component
{
public:
	Image_With_Frames(Texture* tex, int cols, int rows) :
		_tex(tex), timer(), _tr(nullptr), _currentFrame(0), _cols(cols), _rows(rows),
		_width(tex->width()/cols), _height(tex->height()/rows){}

	~Image_With_Frames() {}

	void initComponent() override;
	void update() override;
	void render() override;

	__CMPID_DECL__(ecs::cmp::IMAGE_WITH_FRAMES)
private:
	Texture* _tex;
	Transform* _tr;
	float timer;

	int _cols, _rows, _width, _height;
	int _currentFrame;
};
