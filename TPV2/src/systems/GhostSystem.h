#pragma once
#include "../ecs/System.h"
#include "../utils/Vector2D.h"
#include <vector>

struct Transform;
class VirtualTimer;

class GhostSystem : public ecs::System
{
public:
	GhostSystem();
	virtual ~GhostSystem();
	void initSystem() override;
	void restartSystem();
	void update() override;
	void recieve(const Message&) override;
private:
	static int constexpr MAX_GHOSTS = 10;
	Transform* _pacMan;
	Vector2D _oldPacManPos;

	bool _ghostSpawn = true;
	int _currentTime;
	int _nextTime;
	static constexpr int SPAWN_MARGIN = 5000;
	Vector2D _currentGhostsFrameRange;

	ecs::entity_t createGhost();
};

