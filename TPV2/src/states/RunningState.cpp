#include "RunningState.h"

RunningState::RunningState() {

}

void RunningState::enter()
{
	_player = Game::Instance()->getManager()->getEntities(ecs::grp::PLAYER)[0];
	_playerTr = Game::Instance()->getManager()->getComponent<Transform>(_player);
	_asteroids = Game::Instance()->getManager()->getEntities(ecs::grp::ASTEROID);
	_gunComponent = Game::Instance()->getManager()->getComponent<Gun>(_player);
	sdlutils().musics().at("main_theme").play();

	_fachadaAsteroides = AsteroidsUtils();
	_fachadaFighter = FighterUtils();
}

void
RunningState::update() {
	auto& inputHandler = *InputHandler::Instance();

	//Si no quedan asteroides se acaba el juego
	if (Game::Instance()->getManager()->getEntities(ecs::grp::ASTEROID).empty()) {
		Game::Instance()->setState(Game::GAMEOVER);
	}
	//Si se pulsa la tecla "p" se pausa el juego
	if (inputHandler.isKeyDown(SDLK_p)) {
		Game::Instance()->setState(Game::PAUSED);
	}

	//Se actualizan el player y los asteroides
	Game::Instance()->getManager()->update();

	//Comprobar colisiones entre asteroides y cazas/asteroides y balas
	if (checkPlayerCollisions(_playerTr, _asteroids)) {
		if (_fachadaFighter.update_lives(-1) > 0) {
			Game::Instance()->setState(Game::NEWROUND);
		}
		else {
			Game::Instance()->setState(Game::GAMEOVER);
		}
	}
	checkBulletCollisions(_gunComponent, _asteroids);

	//Se renderizan el player y los asteroides
	Game::Instance()->getManager()->render();

	//Se refrescan las entidades para eliminar las entidades muertas
	Game::Instance()->getManager()->refresh();

	//Se añade un nuevo asteroide cada 5 segundos
	if (sdlutils().virtualTimer().currRealTime() > _waitTime) {
		_fachadaAsteroides.create_asteroids(1);
		_waitTime += 5000.0f;
	}

}

bool
RunningState::checkPlayerCollisions(Transform* playerTr, std::vector<ecs::entity_t> asteroids) {
	bool collision = false;
	Transform* asteroidTr;

	int i = 0;
	while (i < asteroids.size() && !collision) {
		asteroidTr = Game::Instance()->getManager()->getComponent<Transform>(asteroids[i]);
		collision = Collisions::collidesWithRotation(playerTr->getPos(), playerTr->getWidth(), playerTr->getHeight(),
			playerTr->getRotation(), asteroidTr->getPos(), asteroidTr->getWidth(), asteroidTr->getHeight(), asteroidTr->getRotation());
		i++;
	}

	return collision;
}

void
RunningState::checkBulletCollisions(Gun* _gunComponent, std::vector<ecs::entity_t> asteroids) {
	Gun::iterator _bulletIterator = _gunComponent->begin();
	Transform* asteroidTr;

	for (_bulletIterator;_bulletIterator != _gunComponent->end(); ++_bulletIterator)
	{
		if (_bulletIterator->used)
		{
			for (int i = 0; i < asteroids.size(); ++i)
			{
				asteroidTr = Game::Instance()->getManager()->getComponent<Transform>(asteroids[i]);
				if (Collisions::collidesWithRotation(_bulletIterator->pos, _bulletIterator->width, _bulletIterator->height,
					_bulletIterator->rot, asteroidTr->getPos(), asteroidTr->getWidth(), asteroidTr->getHeight(), asteroidTr->getRotation()))
				{
					_fachadaAsteroides.split_asteroid(asteroids[i]);
					_bulletIterator->used = false;
				}
			}
		}
	}
}

void
RunningState::leave() {}