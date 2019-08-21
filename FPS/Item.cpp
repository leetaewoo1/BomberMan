#include "pch.h"
#include "Item.h"


Item::Item(int x, int y, eType type) : MapObject(x, y, type)
{
}

Item::~Item()
{
}

Interaction Item::Interact(Hero* hero)
{
	switch (type)
	{
	case eType::SPEED_UP:
		if (hero->Speed > 7.0f)
		{
			hero->Speed -= 1.0f;
		} break;
	case eType::RANGE_UP:
		if (hero->BombRange < 7)
		{
			++hero->BombRange;
		} break;
	case eType::COUNT_UP:
		if (hero->BombCnt < 5)
		{
			++hero->BombCnt;
			++hero->Remains;
		} break;
	}
	gotoxy(4, 4);
	cout << "¸Ô¾ú´Ù" << endl;
	Over();
	return Interaction{ true };
}
