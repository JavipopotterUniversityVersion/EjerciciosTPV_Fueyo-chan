#pragma once
#include "../ecs/System.h"
#include <vector>

struct Transform;
class VirtualTimer;

class GhostSystem : public ecs::System
{
public:
	GhostSystem();
	virtual ~GhostSystem();
	void initSystem() override;
	void update() override;
	void recieve(const Message&) override;
private:
	static int constexpr MAX_GHOSTS = 10;
	std::vector<Transform*> _ghostsTr;
	Transform* _pacMan;

	int _currentTime;
	int _nextTime;
	static constexpr int SPAWN_MARGIN = 5000;

	ecs::entity_t createGhost();
};

