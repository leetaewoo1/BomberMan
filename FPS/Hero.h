#pragma once
#include "Character.h"
#include "Bomb.h"


class Hero:public Character
{
public:
	Hero() = delete;
	Hero(int x, int y, eType type) :Character(x, y, type) { Speed = 10.0f; }
	~Hero(){}

	virtual float ConvertSpeed() { return Speed / 100.0f; }
	virtual Interaction Interact(class Hero* hero) override 
	{
		assert(false && "not here");
		return Interaction{ true };
	}

public:

	vector<Bomb*> Bombs;

	int BombRange = 1;
	int BombCnt = 1;
	int Remains = 1;
	int Index = 0;
};

