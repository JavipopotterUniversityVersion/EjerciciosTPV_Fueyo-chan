// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include "../sdlutils/SDLUtils.h"


class LittleWolf;
class Networking;

class Game : public Singleton<Game> {
public:
	Game();
	virtual ~Game();
	bool init(const char *map);
	bool initGame(char* host, Uint16 port);
	void start();
	inline LittleWolf* little_wolf() { return _little_wolf; }
private:
	LittleWolf *_little_wolf;
	Networking* net_;
};

