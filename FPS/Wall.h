#pragma once
#include "MapObject.h"

class Wall :public MapObject
{
public:
	Wall() = delete;
	Wall(int x, int y, eType type) :MapObject(x, y, type) {}
	~Wall() {}

	virtual Interaction Interact(class Hero* hero)override
	{
		return Interaction{ false };
	}

	virtual Interaction Interact(class Monster* mon)
	{
		return Interaction{ false };
	}

	virtual void Over() {};
};

