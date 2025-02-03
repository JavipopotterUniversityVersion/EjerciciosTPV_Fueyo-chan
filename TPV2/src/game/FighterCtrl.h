#pragma once
#include "InputComponent.h"
class Container;

class FighterCtrl : public InputComponent
{
private:
public:
	FighterCtrl() {}
	virtual ~FighterCtrl() {}

	void handleInput(Container* o) override;
};

