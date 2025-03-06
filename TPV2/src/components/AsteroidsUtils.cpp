#include "../facade/AsteroidsUtils.h"
#include "../ecs/Entity.h"
#include "../game/Game.h"
#include "../components/Transform.h"
#include "../components/Image_With_Frames.h"
#include "../components/Image.h"
#include "../sdlutils/SDLUtils.h"
#include "../components/Generations.h"
#include "../components/Follow.h"
#include "../components/TowardsDestination.h"
#include "../components/ShowAtOppositeSide.h"
#include <vector>

AsteroidsUtils::AsteroidsUtils() : _manager(Game::Instance()->getManager()) {}

void AsteroidsUtils::create_asteroids(int n, Vector2D p)
{
	if (n <= 0) return;

	for(int i = 0; i < 2; i++)
	{
		ecs::entity_t _asteroid = _manager->addEntity(ecs::grp::ASTEROID);
		Transform* tr = _manager->addComponent<Transform>(_asteroid, p.getX(), p.getY());
		_manager->addComponent<Image_With_Frames>(_asteroid, &sdlutils().images().at("asteroid"), 6, 5);
		_manager->addComponent<Generations>(_asteroid, n-1);
		_manager->addComponent<ShowAtOppositeSide>(_asteroid);

		int s = sdlutils().rand().nextInt(1, 3);

		if (sdlutils().rand().nextInt(0, 2) == 0) _manager->addComponent<Follow>(_asteroid, s);
		else _manager->addComponent<TowardsDestination>(_asteroid, s);

		int r = sdlutils().rand().nextInt(0, 360);
		tr->addRotation(r);

		tr->setWidthAndHeight(float(n-1) / 2 * tr->getHeight());
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
	create_asteroids(gn->getGeneration(), _manager->getComponent<Transform>(a)->getPos());
}