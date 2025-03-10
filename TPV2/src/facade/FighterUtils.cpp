#pragma once
#include "FighterUtils.h"
#include "../ecs/Manager.h"
#include "../game/Game.h"
#include "../components/Image_With_Frames.h";
#include "../components/Health.h"
#include "../components/Transform.h"
#include "../components/FighterCtrl.h"
#include "../components/Deacceleration.h"
#include "../sdlutils/SDLUtils.h"
#include "../components/Image.h"
#include "../components/Gun.h"
#include "../components/Health.h"
#include "../components/ShowAtOppositeSide.h"

FighterUtils::FighterUtils() : _fighter(nullptr), _manager(Game::Instance()->getManager())
{
	if(Game::Instance()->getManager()->getEntities(ecs::grp::PLAYER).size() > 0)
		_fighter = Game::Instance()->getManager()->getEntities(ecs::grp::PLAYER)[0];
}

void FighterUtils::create_fighter()
{
	_fighter = _manager->addEntity(ecs::grp::PLAYER);
	_manager->addComponent<Transform>(_fighter, sdlutils().width()/2, sdlutils().height()/2);
	_manager->addComponent<Image>(_fighter,&sdlutils().images().at("fighter"));
	_manager->addComponent<FighterCrtl>(_fighter);
	_manager->addComponent<Deacceleration>(_fighter);
	_manager->addComponent<ShowAtOppositeSide>(_fighter);
	_manager->addComponent<Health>(_fighter, 3);
	_manager->addComponent<Gun>(_fighter);
	std::cout << "COMp-id: " << _fighter << std::endl;
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
	return _manager->getComponent<Health>(_fighter)->GetHealth();
}