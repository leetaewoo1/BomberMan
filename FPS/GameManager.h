#pragma once
#include "MapObject.h"
#include "Hero.h"
#include "Monster.h"
#include "SceneManager.h"
#include "Item.h"
#include "Block.h"
#include "Wall.h"


class GameManager
{
public:
	GameManager();
	~GameManager();
public:
	void Init();
	void Render();
	void Update(float a_fDeltaTime);
	void Loge();

	void BombEffect(Bomb*bomb);
	bool Explode(int x, int y);
	void ExplodeEffect(Bomb*bomb);
	bool RemoveEffect(int x, int y);

	void HeroDeath();
	void ObjectRemove();
	void Clear(int x, int y);
	void Delete();

	void Complete();

	Item*MakeItem(int x, int y);
	SceneManager*SceneMan = SceneMng();

private:

	char**pMap = nullptr;
	inline static int stage = 1;

	vector<MapObject*>Objects;
	vector<Monster*>Monsters;
	vector<Block*>Blocks;
	vector <Item*>Items;
	vector<Wall*>Walls;

	Hero* MyHero;

};

