#pragma once
#include "../components/Image.h"
#include <queue>

class Image_With_Frames : public ecs::Component
{
public:
	Image_With_Frames() : _img(), _textures(), timer() {}
	~Image_With_Frames() {}

	void initComponent() override;
	void update() override;
private:
	Image* _img;
	std::queue<Texture*> _textures;
	float timer;
};