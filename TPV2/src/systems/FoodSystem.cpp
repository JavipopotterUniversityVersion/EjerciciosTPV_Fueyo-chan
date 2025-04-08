#include "../systems/FoodSystem.h"
#include "../sdlutils/SDLUtils.h"
#include "../ecs/Manager.h"
#include "../components/WonderFruitComponent.h"
#include "../components/Transform.h"
#include "../components/Image.h"
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

void FoodSystem::update() {
	std::vector<ecs::entity_t> wonderFruits = _mngr->getEntities(ecs::grp::WONDER_FRUITS);
	for (ecs::entity_t fruit : wonderFruits) {
		WonderFruitComponent* wonderComp = _mngr->getComponent<WonderFruitComponent>(fruit);

		if (wonderComp->nextTime >= sdlutils().virtualTimer().currTime()) {
			Image* wonderFruitImg = _mngr->getComponent<Image>(fruit);
			if (wonderComp->inWonderState) {
				wonderComp->inWonderState = false;
				wonderFruitImg->_tex = &sdlutils().images().at("cherry");
				wonderComp->nextTime = sdlutils().virtualTimer().currTime() + wonderComp->N();
			}
			else{
				wonderComp->inWonderState = true;
				wonderFruitImg->_tex = &sdlutils().images().at("pear");
				wonderComp->nextTime = sdlutils().virtualTimer().currTime() + wonderComp->M();
			}
		}
	}
}

void FoodSystem::createFruit(int x, int y) {
	bool isWonder = _rng.nextInt(0, 101) > 90;
	ecs::entity_t fruit = _mngr->addEntity(isWonder ? ecs::grp::WONDER_FRUITS : ecs::grp::FRUITS);

	float s = 50.0f;
	_mngr->addComponent<Transform>(fruit, Vector2D(x,y), Vector2D(), s, s, 0);
	_mngr->addComponent<Image>(fruit, &sdlutils().images().at("cherry"));

	if (isWonder) {
		int n = _rng.nextInt(1, 11);
		int m = _rng.nextInt(1, 6);
		WonderFruitComponent* wonderComp = _mngr->addComponent<WonderFruitComponent>(fruit, n, m);
		wonderComp->nextTime = sdlutils().virtualTimer().currTime() + wonderComp->N();
	}
}