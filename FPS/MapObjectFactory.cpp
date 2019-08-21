#include "pch.h"
#include "MapObjectFactory.h"
#include "MapObject.h"

#include "Wall.h"
#include "Block.h"
#include "Monster.h"

#include "Item.h"
#include "Bomb.h"

MapObject* MapObjectFactory::MakeMapObject(int x,int y,eType type)
{
	MapObject* Obj = nullptr;

	switch (type)
	{
	case eType::None:break;
	case eType::Wall:		Obj = new Wall(x, y, type); break;
	case eType::Block:		Obj = new Block(x, y, type); break;
	case eType::SPEED_UP:	Obj = new Item(x, y, type); break;
	case eType::COUNT_UP:	Obj = new Item(x, y, type); break;
	case eType::RANGE_UP:	Obj = new Item(x, y, type); break;
	default:break;
	}

	return Obj;
}