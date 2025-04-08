#pragma once
#include "../ecs/Component.h"

struct WonderFruitComponent : public ecs::Component {
public:
	WonderFruitComponent(int N, int M);
	virtual ~WonderFruitComponent();

	bool inWonderState;
	int nextTime;

	inline int const N() { return _n; }
	inline int const M() { return _m; }

private:
	int _n, _m;
};

