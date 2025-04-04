#pragma once
#include "../ecs/System.h"
#include <vector>

struct Transform;
class VirtualTimer;

class GhostSystem : public ecs::System
{
public:
	GhostSystem(VirtualTimer* vt);
	virtual ~GhostSystem();
	void initSystem() override;
	void update() override;
private:
	static int constexpr MAX_GHOSTS = 10;
	std::vector<Transform*> _ghostsTr;
	Transform* _pacMan;
	VirtualTimer* _vt;

	Uint32 _nextTime = 0;
	static constexpr Uint32 SPAWN_MARGIN = 500;

	ecs::entity_t createGhost();
};

