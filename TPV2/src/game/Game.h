// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once

#include <vector>

#include "../ecs/Entity.h"
#include "../ecs/Manager.h"
#include "../utils/Singleton.h"
#include "GameState.h"
class GameOverState;
class NewGameState;
class NewRoundState;
class PausedState;
class RunningState;

class Game : public Singleton<Game> {
public:
	Game();
	virtual ~Game();
	void initGame();
	bool init();
	void start();
	inline ecs::Manager* getManager() { return _manager; }

	enum State {
		RUNNING, PAUSED, NEWGAME, NEWROUND, GAMEOVER
	};
	inline void setState(State s) {
		if (_current_state != nullptr) {
			_current_state->leave();
		}
		switch (s) {
		case RUNNING:
			_current_state = _runing_state;
			break;
		case PAUSED:
			_current_state = _paused_state;
			break;
		case NEWGAME:
			_current_state = _newgame_state;
			break;
		case NEWROUND:
			_current_state = _newround_state;
			break;
		case GAMEOVER:
			_current_state = _gameover_state;
			break;
		default:
			break;
		}
		_current_state->enter();
	}
private:
	ecs::Manager* _manager;
	std::vector<ecs::entity_t> _entities;
	GameState* _current_state;
	GameState* _paused_state;
	GameState* _runing_state;
	GameState* _newgame_state;
	GameState* _newround_state;
	GameState* _gameover_state;
};

