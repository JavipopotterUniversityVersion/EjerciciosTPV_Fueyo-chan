// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include "../ecs/System.h"
#include "../sdlutils/SDLUtils.h"

class Texture;
struct Transform;
struct SDL_Rect;
struct FramedImage;

class RenderSystem: public ecs::System {
public:
	RenderSystem();
	virtual ~RenderSystem();
	void initSystem() override;
	void update() override;
private:
	void drawPacMan();
	void drawGroup(ecs::grp::grpId id);
	void drawMsgs();
	void draw(Transform *tr, Texture *tex);
	void draw(Transform* tr, FramedImage* framedImage);
	void drawHearts();

	static int constexpr FRAME_SPACE = 10;
	int _currentFrameStep;

	static constexpr int HEART_SIZE = 30;
	Texture* _heartTex = &sdlutils().images().at("heart");
};

