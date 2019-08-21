#pragma once
#include "MapObject.h"
class Bomb : public MapObject
{
public:
	enum { ExplodCount = 15, };
public:
	Bomb() = delete;
	Bomb(int x, int y, eType type) : MapObject(x, y, type) {}
	~Bomb() {}

	int ExplodCnt = SecondCount;
	int ExplodEffectCnt = ExplodCount;
	bool bExploded = false;

	virtual float ConvertSpeed() { return BombCountSpeed / 100.0f; }
	float ConvertEffectSpeed() { return BombEffectSpeed / 100.0f; }

	virtual Interaction Interact(class Hero* hero) override { return Interaction{ false }; }
	virtual Interaction Interact(Monster* mon) override		{ return Interaction{ false }; }

private:

	float BombEffectSpeed = 1 / ExplodCount;
	float BombCountSpeed = 100.0f;
};

