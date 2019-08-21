#include "pch.h"
#include "MapObject.h"


MapObject::MapObject(int x, int y, eType type) :type(type)
{
	pos.X = x;
	pos.Y = y;
}


MapObject::~MapObject()
{
}

eType MapObject::GetObjectType()
{
	return type;
}

bool MapObject::GetOverState()
{
	return bOver;
}

void MapObject::Over()
{
	bOver = true;
}

COORD MapObject::GetPos()
{
	return pos;
}

bool MapObject::IsCrossed(int x, int y)
{
	if (pos.X == x && pos.Y == y) { return true; }
	return false;
}