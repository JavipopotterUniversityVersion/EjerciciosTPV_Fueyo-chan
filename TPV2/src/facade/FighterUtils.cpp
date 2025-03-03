#pragma once
#include "FighterUtils.h"
#include "../ecs/Manager.h"
#include "../game/Game.h"
#include "../components/Image.h"
#include "../components/Health.h"
#include "../components/Transform.h"

FighterUtils::FighterUtils() : _fighter(nullptr), _manager(Game::Instance()->getManager()) {}

void FighterUtils::create_fighter()
{
	_fighter = _manager->addEntity(ecs::grp::PLAYER);
	_manager->addComponent<Transform>(_fighter,0,0);
	//_manager->addComponent<Image>(_fighter);
}

void FighterUtils::reset_fighter()
{
	_manager->getComponent<Transform>(_fighter)->resetPosition();
}

void FighterUtils::reset_lives()
{
	_manager->getComponent<Health>(_fighter)->ResetHealth();
}

int FighterUtils::update_lives(int n)
{
	_manager->getComponent<Health>(_fighter)->LoseHealth(-n);
	return n;
}