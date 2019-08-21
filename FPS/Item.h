#pragma once
#include "MapObject.h"
#include "Hero.h"
#include "Monster.h"

class Item : public MapObject
{
public:
	Item() = delete;
	Item(int x, int y, eType type);
	~Item();

	virtual Interaction Interact(Hero* hero) override;

	virtual Interaction Interact(Monster* mon) override {
		Over();
		return Interaction{ true };
	}

};

