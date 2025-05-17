#include "../systems/FoodSystem.h"
#include "../sdlutils/SDLUtils.h"
#include "../ecs/Manager.h"
#include "../components/WonderFruitComponent.h"
#include "../components/Transform.h"
#include "../components/FramedImage.h"
#include "../game/AnimationUtility.h"
#include "../game/Game.h"
#include <vector>


FoodSystem::FoodSystem() : _rng() {}
FoodSystem::~FoodSystem() {}

void FoodSystem::initSystem() {
	for (int i = 0; i < sdlutils().width() / GRID_SIZE; i++){
		for (int c = 0; c < sdlutils().height() / GRID_SIZE; c++){
			createFruit(i * GRID_SIZE, c * GRID_SIZE);
		}
	}
}

void FoodSystem::restartSystem() {
	auto& fruits = _mngr->getEntities(ecs::grp::FRUITS);
	auto& wonderFruits = _mngr->getEntities(ecs::grp::WONDER_FRUITS);
	
	for (ecs::entity_t fruit : fruits) {
		_mngr->setAlive(fruit, false);
	}
	for (ecs::entity_t wonderFruit : wonderFruits) {
		_mngr->setAlive(wonderFruit, false);
	}

	initSystem();
}

void FoodSystem::update() {
	std::vector<ecs::entity_t> wonderFruits = _mngr->getEntities(ecs::grp::WONDER_FRUITS);
	for (ecs::entity_t fruit : wonderFruits) {
		WonderFruitComponent* wonderComp = _mngr->getComponent<WonderFruitComponent>(fruit);

		if (wonderComp->nextTime <= sdlutils().currTime()) {
			FramedImage* wonderFruitImg = _mngr->getComponent<FramedImage>(fruit);
			if (wonderComp->inWonderState) {
				wonderComp->inWonderState = false;
				wonderFruitImg->setFrameRange(AnimationUtility::getCherry());
				wonderComp->nextTime = sdlutils().currTime() + wonderComp->N();
			}
			else{
				wonderComp->inWonderState = true;
				wonderFruitImg->setFrameRange(AnimationUtility::getPear());
				wonderComp->nextTime = sdlutils().currTime() + wonderComp->M();
			}
		}
	}
}

void FoodSystem::createFruit(int x, int y) {
	bool isWonder = _rng.nextInt(0, 101) > 90;
	ecs::entity_t fruit = _mngr->addEntity(isWonder ? ecs::grp::WONDER_FRUITS : ecs::grp::FRUITS);

	float s = 25.0f;
	_mngr->addComponent<Transform>(fruit, Vector2D(x + 40,y + 40), Vector2D(), s, s, 0);
	_mngr->addComponent<FramedImage>(fruit, AnimationUtility::getCherry());

	if (isWonder) {
		int n = _rng.nextInt(1000, 11000);
		int m = _rng.nextInt(1000, 6000);
		WonderFruitComponent* wonderComp = _mngr->addComponent<WonderFruitComponent>(fruit, n, m);
		wonderComp->nextTime = sdlutils().currTime() + wonderComp->N();
	}
}

void FoodSystem::recieve(const Message& m) {
	switch (m.id) {
		case _m_GAME_OVER:
			restartSystem();
			break;
		case _m_PACMAN_FOOD_COLLISION:
			sdlutils().soundEffects().at("pacman_eat").play();

			std::vector<ecs::entity_t> fruits;

			if(m.pacman_food_collision_data.is_wonder) fruits = _mngr->getEntities(ecs::grp::WONDER_FRUITS);
			else fruits = _mngr->getEntities(ecs::grp::FRUITS);

			_mngr->setAlive(fruits[m.pacman_food_collision_data.index], false);

			if (_mngr->getEntities(ecs::grp::WONDER_FRUITS).size() + _mngr->getEntities(ecs::grp::FRUITS).size() <= 0) {
				sdlutils().soundEffects().at("pacman_won").play();
				Game::Instance()->setState(Game::GAMEOVER);
			}
			break;
	}
}