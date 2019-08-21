#pragma once
#include "MapObject.h"
#include "Item.h"

class Block:public MapObject
{
public:
	Block() = delete;
	Block(int x, int y, eType type) : MapObject(x, y, type) {}
	~Block() {}

	virtual Interaction Interact(class Hero* hero) override
	{
		return Interaction{ false };
	}

	virtual Interaction Interact(Monster* mon) override
	{
		return Interaction{ false };
	}

};

