#pragma once
#include "pch.h"

using namespace std;

struct Interaction
{

	bool bMove = false;

	void Clear()
	{
		bMove = true;
	}
};

enum class eUpdateState
{
	Run,
	Final,
};

enum class eScene
{
	IntroScene,
	GameScene,
	OverScene,

	// 씬이랑은 관계없지만 나름 편하게 쓸법한 define 비슷한 값
	Scene_First = IntroScene,
};

enum class eType
{
	None = 32,

	Wall = 35,
	Block = 64,

	Hero = 72,
	// 몬스터 종류
	Monster = 109,
	EliteMonster = 77,
	BossMonster = 43,

	Bomb = 66,
	//아이템 종류
	SPEED_UP = 83,
	COUNT_UP = 33,
	RANGE_UP = 42,
};

enum eKey
{
	NONE = 0,

	UP = 72,
	DOWN = 80,
	LEFT = 75,
	RIGHT = 77,
	SELECT = 13,

	SPACE = 32,
};

enum eSize
{
	CONSOLE_X = 160,
	CONSOLE_Y = 42,

	INTRO_X = 106,
	INTRO_Y = 14,

	OVER_X = 106,
	OVER_Y = 11,

	MAP_X = 50,
	MAP_Y = 25,

	X = CONSOLE_X / 3,
	Y = CONSOLE_Y / 5,
};

enum Count
{
	MaxStageCount = 3,

	SecondCount = 4,
	BombNumberCount = 5,

	MonsterMoveTurn = 4,
	MonsterMoveCount = 5,
};

#define SAFE_DELETE(x)		{if((x)!=nullptr) {delete (x); (x) = nullptr; } }
#define SAFE_DELETE_ARR(x)	{if((x) != nullptr) {delete[] (x); (x) = nullptr; } }

void gotoxy(size_t x, size_t y);
char GetKeyInput();
void delay(clock_t t);