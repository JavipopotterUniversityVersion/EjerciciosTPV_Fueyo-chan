#pragma once
#include "../components/Image.h"

class Image_With_Frames : public ecs::Component
{
public:
	Image_With_Frames() : _img() {}
	~Image_With_Frames() {}

	void initComponent() override;
	void update() override;
private:
	Image* _img;
	Texture* _textures;
};