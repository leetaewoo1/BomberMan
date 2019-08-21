#include "pch.h"
#include "Monster.h"


Monster::Monster(int x,int y,eType type):Character(x,y,type)
{
	SetSpeed();
	int Random = rand() % 4;
	switch (Random)
	{
	case 0:Dir = UP; break;
	case 1:Dir= DOWN; break;
	case 2:Dir = LEFT; break;
	case 3: Dir = RIGHT; break;
	default:break;
	}
}


Monster::~Monster()
{
}

void Monster::SetSpeed()
{
	switch (type)
	{
	case eType::Monster: Speed = 70.0f; break;
	case eType::EliteMonster: Speed = 50.0f; break;
	case eType::BossMonster: Speed = 30.0f; break;
	default:break;
	}
}

void Monster::DirChange()
{
	int RandTrun = rand() % 3;

	switch (Dir)
	{
	case UP:
	{
		switch (RandTrun)
		{
		case 0: Dir = DOWN; break;
		case 1: Dir = LEFT; break;
		case 2: Dir = RIGHT;
		}
	}break;
	case DOWN:
	{
		switch (RandTrun)
		{
		case 0:Dir = UP; break;
		case 1:Dir = LEFT; break;
		case 2: Dir = RIGHT;
		}
	}break;
	case LEFT:
	{
		switch (RandTrun)
		{
		case 0: Dir = DOWN; break;
		case 1:Dir = UP; break;
		case 2: Dir = RIGHT;
		}
	}break;
	case RIGHT:
	{
		switch (RandTrun)
		{
		case 0:Dir = DOWN; break;
		case 1: Dir = LEFT; break;
		case 2:Dir = UP; break;
		}
	}break;
	default:break;
	}
}

Interaction Monster::Interact(Hero*hero)
{
	hero->Over();
	return Interaction{ false };
}
