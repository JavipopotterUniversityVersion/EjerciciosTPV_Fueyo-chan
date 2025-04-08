#pragma once
#include "../ecs/System.h"

class InmunitySystem : public ecs::System
{
public:
	InmunitySystem();
	virtual ~InmunitySystem();
	void initSystem() override;
	void update() override;
	void recieve(const Message&) override;
private:
	static int constexpr INMUNE_TIME = 10000;
	int _nextTime;
	bool isInmune;
};