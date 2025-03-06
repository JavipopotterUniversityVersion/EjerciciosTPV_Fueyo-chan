#include "Health.h"


Health::~Health() {}

void
Health::render() {
	int width = sdlutils().width();
	int height = sdlutils().height();

	for (int c = 0; c < _health; c++)
	{
		SDL_Rect rect{ width / 5 * (c + 1), height / 10, HEART_SIZE, HEART_SIZE };
		_tex->render(rect);
	}
}
