#pragma once
#include "MapObject.h"

class MapObjectFactory
{
public:
	static MapObject* MakeMapObject(int x, int y, eType type);
};

