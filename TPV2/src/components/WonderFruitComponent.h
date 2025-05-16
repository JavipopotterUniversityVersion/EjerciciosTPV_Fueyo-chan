#pragma once
#include "../ecs/Component.h"

struct WonderFruitComponent : public ecs::Component {
public:
	WonderFruitComponent(int N, int M) : _n(N), _m(M), nextTime(0), inWonderState(false) {}
	virtual ~WonderFruitComponent() {}

	bool inWonderState;
	int nextTime;

	inline int N() const { return _n; }
	inline int M() const { return _m; }

private:
	int _n, _m;
};

