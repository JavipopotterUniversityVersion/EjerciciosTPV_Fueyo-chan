#pragma once
#include "../ecs/Component.h"

struct WonderFruitComponent : public ecs::Component {
public:
	WonderFruitComponent(int N, int M) : _n(N), _m(M), nextTime(0), _inWonderState(false) {}
	virtual ~WonderFruitComponent() {}

	int nextTime;
	inline bool inWonderState() const { return _inWonderState; }
	inline void setWonderState(bool value) { _inWonderState = value; }

	inline int N() const { return _n; }
	inline int M() const { return _m; }

private:
	bool _inWonderState;
	int _n, _m;
};

