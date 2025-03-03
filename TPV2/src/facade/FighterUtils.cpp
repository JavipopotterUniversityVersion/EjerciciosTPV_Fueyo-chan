#pragma once
#include "FighterUtils.h"
#include "ecs/Manager.h"
#include "../components/Image.h"
#include "../components/Health.h"

FighterUtils::FighterUtils(ecs::Manager* manager) : _fighter(nullptr), _manager(manager) {}

void FighterUtils::create_fighter()
{
	_fighter = _manager->addEntity(ecs::grp::PLAYER);
	_manager->addComponent<Transform>();
	_manager->addComponent<Image>();
}

void FighterUtils::reset_fighter()
{
	_manager->getComponent<
}

void FighterUtils::reset_lives()
{
	_manager->getComponent<Health>(_fighter)->ResetHealth();
}

int FighterUtils::update_lives(int n)
{
	
}