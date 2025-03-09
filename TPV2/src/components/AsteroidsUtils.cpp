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

void AsteroidsUtils::create_asteroids(int n)
{
	if (n <= 0) return;

	for(int i = 0; i < n; i++)
	{
		ecs::entity_t _asteroid = _manager->addEntity(ecs::grp::ASTEROID);

		Vector2D pos = Vector2D();
		int rndBorder = sdlutils().rand().nextInt(0, 4);
		if (rndBorder == 0) pos = { 0, sdlutils().rand().nextInt(0, 680) }; //Borde izq.
		else if (rndBorder == 1) pos = { 800, sdlutils().rand().nextInt(0, 680) }; //Borde der.
		else if (rndBorder == 2) pos = { sdlutils().rand().nextInt(0, 800), 0 }; //Borde arriba
		else if (rndBorder == 3) pos = { sdlutils().rand().nextInt(0, 800), 680 }; //Borde abajo
		Transform* tr = _manager->addComponent<Transform>(_asteroid, pos.getX(), pos.getY());

		_manager->addComponent<Image_With_Frames>(_asteroid, &sdlutils().images().at("asteroid"), 6, 5);
		_manager->addComponent<Generations>(_asteroid, sdlutils().rand().nextInt(1, 4));
		_manager->addComponent<ShowAtOppositeSide>(_asteroid);

		int s = sdlutils().rand().nextInt(1, 3);

		if (sdlutils().rand().nextInt(0, 2) == 0) _manager->addComponent<Follow>(_asteroid, s);
		else _manager->addComponent<TowardsDestination>(_asteroid, s);

		int r = sdlutils().rand().nextInt(0, 360);
		tr->addRotation(r);

		tr->setWidthAndHeight(10.0f + (5.0f * _manager->getComponent<Generations>(_asteroid)->getGeneration()));
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
	Transform* _aTr = _manager->getComponent<Transform>(a);
	_manager->setAlive(a, false);

	if (gn->getGeneration() > 1) {
		for (int i = 0; i < 2; i++)
		{
			ecs::entity_t _asteroid = _manager->addEntity(ecs::grp::ASTEROID);

			Vector2D pos = {_aTr->getPos().getX() + sdlutils().rand().nextInt(-10,11),
				_aTr->getPos().getY() + sdlutils().rand().nextInt(-10,11) };

			Transform* tr = _manager->addComponent<Transform>(_asteroid, pos.getX(),pos.getY());

			_manager->addComponent<Image_With_Frames>(_asteroid, &sdlutils().images().at("asteroid"), 6, 5);
			_manager->addComponent<Generations>(_asteroid, gn->getGeneration() - 1);
			_manager->addComponent<ShowAtOppositeSide>(_asteroid);

			float s = sdlutils().rand().nextInt(1, 10)/10.0f;

			if (sdlutils().rand().nextInt(0, 2) == 0) _manager->addComponent<Follow>(_asteroid, s);
			else {
				_manager->addComponent<TowardsDestination>(_asteroid, s);
				_manager->getComponent<TowardsDestination>(_asteroid)->
					forceDirection({400 + sdlutils().rand().nextInt(-100,101), 340 + sdlutils().rand().nextInt(-100,101)});
			}

			int r = sdlutils().rand().nextInt(0, 360);
			tr->addRotation(r);

			tr->setWidthAndHeight(10.0f + (5.0f * (gn->getGeneration() - 1)));
			std::cout << "asteroid was created succesfully" << std::endl;
		}
	}
}