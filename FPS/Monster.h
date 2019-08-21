#pragma once
#include "Character.h"
#include "Hero.h"

class Monster :public Character
{
	enum { Max = 10000000, };
public:
	Monster() = delete;
	Monster(int x, int y, eType type);
	~Monster();

	int MoveCnt = 0;
	eKey Dir;

	void SetSpeed();
	void DirChange();
	void Stop() { Speed = Max; }

	virtual float ConvertSpeed() { return Speed / 100.0f; }
	virtual Interaction Interact(Hero* hero)override;
};

