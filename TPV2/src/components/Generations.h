#pragma once
#include "../ecs/Component.h"

class Generations : public ecs::Component
{
public:
	Generations(int generation) : _generation(generation) {};
	~Generations() {};

	__CMPID_DECL__(ecs::cmp::GENERATIONS)
	inline int getGeneration() { return _generation; }

private:
	int _generation;
};