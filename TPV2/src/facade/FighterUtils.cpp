#pragma once
#include "FighterUtils.h"
#include "ecs/Manager.h"
#include "../components/Image.h"

FighterUtils::FighterUtils(ecs::Manager* manager) : _fighter(nullptr), _manager(manager) {}

void FighterUtils::create_fighter()
{
	ecs::Manager* mng = new ecs::Manager();
	_fighter = mng->addEntity(ecs::grp::PLAYER);
	mng->addComponent<Transform>();
	mng->addComponent<Image>();
}

void FighterUtils::reset_fighter()
{

}

void FighterUtils::reset_lives()
{

}

int FighterUtils::update_lives(int n)
{
	
}