#pragma once
#include "../components/Image.h"

class Image_With_Frames : public ecs::Component
{
public:
	Image_With_Frames() : _img() {}
	~Image_With_Frames() {}
private:
	Image* _img;
};