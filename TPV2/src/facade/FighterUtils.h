#pragma once
#include "FighterFacade.h"
#include "../ecs/Entity.h"
#include "../ecs/Manager.h"

class FighterUtils : public FighterFacade
{
public:
	FighterUtils(ecs::Manager* manager);
	virtual ~FighterUtils() {}
	void create_fighter() override;
	void reset_fighter() override;
	void reset_lives() override;
	int update_lives(int n) override;
private:
	ecs::Manager* _manager;
	ecs::entity_t _fighter;
};