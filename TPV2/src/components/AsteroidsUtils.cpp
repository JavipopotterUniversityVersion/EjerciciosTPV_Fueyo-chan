#include "../facade/AsteroidsUtils.h"
#include "../ecs/Entity.h"
#include "../game/Game.h"
#include "../components/Transform.h"
#include "../components/Image_With_Frames.h"
#include "../sdlutils/SDLUtils.h"
#include "../components/Generations.h"
#include <vector>

AsteroidsUtils::AsteroidsUtils() : _manager(Game::Instance()->getManager()) {}

void AsteroidsUtils::create_asteroids(int n)
{
	if (n <= 0) return;

	for(int i = 0; i < 2; i++)
	{
		ecs::entity_t _asteroid = _manager->addEntity(ecs::grp::ASTEROID);
		Transform* tr = _manager->addComponent<Transform>(_asteroid, 2, 2);
		_manager->addComponent<Image_With_Frames>(_asteroid, &sdlutils().images().at("asteroid"), 6, 5);
		_manager->addComponent<Generations>(_asteroid, n-1);

		tr->setWidthAndHeight(n);
		std::cout << "asteroid was created succesfully" << std::endl;
	}
}

void AsteroidsUtils::remove_all_asteroids()
{
	std::vector asteroids = _manager->getEntities(ecs::grp::ASTEROID);
	
	for (ecs::entity_t asteroid : asteroids)
	{
		_manager->setAlive(asteroid, false);
	}

	_manager->refresh();
}

void AsteroidsUtils::split_asteroid(ecs::Entity* a)
{
	Generations* gn = _manager->getComponent<Generations>(a);
	_manager->setAlive(a, false);
	create_asteroids(gn->getGeneration());
}