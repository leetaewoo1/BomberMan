#pragma once
#include "pch.h"

class MapObject
{
public:
	MapObject() = delete;
	MapObject(int x, int y, eType type);
	~MapObject();

public:
	COORD pos;
	eType type;
	bool bOver = false;
	bool bTemp = false;
	float NowTerm = 0.0f;
	float Speed;

	virtual void Temp() { bTemp = true; }
	virtual bool GetOverState();
	virtual void Over();

	virtual eType GetObjectType();
	virtual COORD GetPos();

	virtual bool IsCrossed(int x, int y);
	virtual Interaction Interact(class Hero* hero) = 0;
	virtual Interaction Interact(class Monster* mon)
	{
		return Interaction{ false };
	}
};

