#pragma once
#include "../ecs/System.h"
#include <vector>

struct Transform;

class GhostSystem : public ecs::System
{
public:
	GhostSystem();
	virtual ~GhostSystem();
	void initSystem() override;
	void update() override;
private:
	static int constexpr MAX_GHOSTS = 10;
	std::vector<Transform*> _ghostsTr;
	Transform* _pacMan;
};

