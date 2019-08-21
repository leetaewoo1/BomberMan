#pragma once
#include "MapObject.h"



class Character :public MapObject
{
public:
	Character() = delete;
	Character(int x, int y, eType type) :MapObject(x, y, type) {}
	~Character() {}

	bool bMove = true;

	virtual float ConvertSpeed() = 0;

	virtual void MoveTo(int x, int y)
	{
		pos.X = x;
		pos.Y = y;
	}

	virtual Interaction Interact(class Hero*hero)override
	{
		return Interaction{ false };
	}
};

