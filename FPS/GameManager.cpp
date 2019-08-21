#include "pch.h"
#include "GameManager.h"
#include "MapObjectFactory.h"


GameManager::GameManager()
{
	pMap = new char*[MAP_Y];
	for (int i = 0; i < MAP_Y; ++i)
	{
		pMap[i] = new char[MAP_X];
	}
}

GameManager::~GameManager()
{
	Delete();
}

void GameManager::Clear(int x, int y)
{
	int ConX = CONSOLE_X / 3;
	int ConY = CONSOLE_Y / 5;

	gotoxy(x + ConX, y + ConY);
	cout << " ";
}

//저장(?)
void GameManager::Init()
{
	for (int y = 0; y < MAP_Y; ++y)
	{
		for (int x = 0; x < MAP_X; ++x)
		{
			eType type;
			if (stage == 1)// 맵 좌표 저장
			{
				pMap[y][x] = GameData::Map1[y][x];
				type = (eType)GameData::Map1[y][x];
			}
			else if (stage == 2)
			{
				pMap[y][x] = GameData::Map2[y][x];
				type = (eType)GameData::Map2[y][x];
			}
			else
			{
				pMap[y][x] = GameData::Map3[y][x];
				type = (eType)GameData::Map3[y][x];
			}

			// 몬스터, 벽, 블럭 및 오브젝트 타입별로 벡터에 저장
			if (type == eType::Monster || type == eType::EliteMonster || type == eType::BossMonster)
			{
				Monster* pMon = new Monster(x, y, type);
				Monsters.push_back(pMon);
			}
			else if (type == eType::Block)
			{
				Block*pBlock = new Block(x, y, type);
				Blocks.push_back(pBlock);
			}
			else if (type == eType::Wall)
			{
				Wall* pWall = new Wall(x, y, type);
				Walls.push_back(pWall);
			}
			else
			{
				MapObject* pObj = MapObjectFactory::MakeMapObject(x, y, type);
				if (pObj != nullptr)
				{
					Objects.push_back(pObj);
				}
			}
		}
	}

	MyHero = new Hero(1, 1, eType::Hero);
	Objects.push_back(MyHero);

	for (int i = 0; i < BombNumberCount; ++i)
	{
		Bomb* pBomb = new Bomb(0, 0, eType::Bomb);
		pBomb->bOver = true;
		MyHero->Bombs.push_back(pBomb);
	}

	for (int y = 0; y < MAP_Y; ++y)
	{
		for (int x = 0; x < MAP_X; ++x)
		{
			gotoxy(x + X, y + Y);
			cout << pMap[y][x];
		}
	}
}

void GameManager::Render()
{
	for (auto r : Objects)
	{
		gotoxy(r->GetPos().X + X, r->GetPos().Y + Y);
		cout << (char)r->GetObjectType();
	}

	for (auto r : Monsters)
	{
		gotoxy(r->GetPos().X + X, r->GetPos().Y + Y);
		cout << (char)r->GetObjectType();
	}

	for (int i = 0; i < MyHero->BombCnt; ++i)
	{
		if (MyHero->Bombs[i]->GetOverState() == false)
		{
			gotoxy(MyHero->Bombs[i]->GetPos().X + X, MyHero->Bombs[i]->GetPos().Y + Y);
			cout << (char)MyHero->Bombs[i]->GetObjectType();
		}
	}

	for (auto r : Items)
	{
		gotoxy(r->GetPos().X + X, r->GetPos().Y + Y);
		cout << (char)r->GetObjectType();
	}

	Loge();

}

void GameManager::Update(float a_fDeltaTime)
{
	gotoxy(1, 1);
	cout << a_fDeltaTime;

	int x = MyHero->GetPos().X;
	int y = MyHero->GetPos().Y;

	//hero 움직임
	MyHero->NowTerm += a_fDeltaTime;
	if (MyHero->NowTerm > MyHero->ConvertSpeed())
	{
		MyHero->NowTerm -= MyHero->ConvertSpeed();

		char c = GetKeyInput();

		switch (c)
		{
		case UP: Clear(x, y); --y; break;
		case DOWN: Clear(x, y); ++y; break;
		case LEFT: Clear(x, y); --x; break;
		case RIGHT: Clear(x, y); ++x; break;
		case SPACE:
			if (MyHero->Remains > 0)
			{
				bool Overlap = true;

				for (auto r : MyHero->Bombs)
				{
					if (r->GetOverState() == false)
					{
						if (r->GetPos().X == x && r->GetPos().Y == y) { Overlap = false; }
					}
				}

				if (Overlap == true)
				{
					MyHero->Bombs[MyHero->Index]->bOver = false;
					MyHero->Bombs[MyHero->Index]->pos.X = x;
					MyHero->Bombs[MyHero->Index]->pos.Y = y;
					--MyHero->Remains;
					++MyHero->Index;
					MyHero->Index %= MyHero->BombCnt;
				}
			}break;
		default: break;
		}

		for (auto r : Objects)
		{
			if (r != MyHero && r->IsCrossed(x, y) == true)
			{
				MyHero->bMove = r->Interact(MyHero).bMove;
			}
		}

		for (auto r : Monsters)
		{
			if (r->IsCrossed(x, y) == true)
			{
				MyHero->bMove = r->Interact(MyHero).bMove;
			}
		}

		for (auto r : Blocks)
		{
			if (r->IsCrossed(x, y) == true)
			{
				MyHero->bMove = r->Interact(MyHero).bMove;
			}
		}

		for (auto r : Items)
		{
			if (r->IsCrossed(x, y) == true)
			{
				MyHero->bMove = r->Interact(MyHero).bMove;
			}
		}

		for (auto r : Walls)
		{
			if (r->IsCrossed(x, y) == true)
			{
				MyHero->bMove = r->Interact(MyHero).bMove;
			}
		}

		for (auto r : MyHero->Bombs)
		{
			if (r->GetOverState() == false)
			{
				if (r->IsCrossed(x, y) == true)
				{
					MyHero->bMove = r->Interact(MyHero).bMove;
				}
			}
		}

		if (MyHero->bMove == true)
		{
			MyHero->MoveTo(x, y);
		}
		MyHero->bMove = true;
	}

	// monster 움직임
	for (auto r : Monsters)
	{
		int x = r->GetPos().X;
		int y = r->GetPos().Y;

		r->NowTerm += a_fDeltaTime;

		if (r->NowTerm > r->ConvertSpeed())
		{
			r->NowTerm -= r->ConvertSpeed();
			if (r->MoveCnt == MonsterMoveCount)
			{
				r->MoveCnt = 0;
				r->DirChange();
			}

			Clear(x, y);

			switch (r->Dir)
			{
			case UP:--y; break;
			case DOWN: ++y; break;
			case LEFT: --x; break;
			case RIGHT: ++x; break;
			default:break;
			}
			++r->MoveCnt;

			for (auto v : Objects)
			{
				if (v->IsCrossed(x, y) == true)
				{
					r->bMove = v->Interact(r).bMove;
					if (r->MoveCnt < MonsterMoveTurn) { r->MoveCnt = MonsterMoveTurn; }
				}
			}

			for (auto v : Monsters)
			{
				if (v->IsCrossed(x, y) == true)
				{
					r->bMove = false;
					r->MoveCnt = MonsterMoveCount;
				}
			}

			for (auto v : Walls)
			{
				if (v->IsCrossed(x, y) == true)
				{
					r->bMove = v->Interact(r).bMove;
				}
			}

			for (auto v : Blocks)
			{
				if (v->IsCrossed(x, y) == true)
				{
					r->bMove = v->Interact(r).bMove;
				}
			}

			for (auto v : Items)
			{
				if (v->IsCrossed(x, y) == true)
				{
					r->bMove = v->Interact(r).bMove;
				}
			}

			for (auto v : MyHero->Bombs)
			{
				if (v->GetOverState() == false)
				{
					if (v->IsCrossed(x, y) == true)
					{
						r->bMove = v->Interact(r).bMove;
					}
				}
			}

			if (r->bMove == true)
			{
				r->MoveTo(x, y);
			}
			r->bMove = true;
		}
	}

	// 폭탄 터지기
	for (auto r : MyHero->Bombs)
	{
		if (r->GetOverState() == false)
		{
			r->NowTerm += a_fDeltaTime;

			if (r->NowTerm > r->ConvertSpeed())
			{
				r->NowTerm -= r->ConvertSpeed();
				--r->ExplodCnt;
			}
			if (r->ExplodCnt == 0)
			{
				r->Over();
				BombEffect(r);
				r->bExploded = true;
				r->ExplodCnt = SecondCount;
			}
		}
	}

	// 터진 후 죽이기
	for (auto r : MyHero->Bombs)
	{
		if (r->bExploded == true)
		{
			r->NowTerm += a_fDeltaTime;

			if (r->NowTerm > r->ConvertEffectSpeed())
			{
				r->NowTerm -= r->ConvertEffectSpeed();
				BombEffect(r);
				--r->ExplodEffectCnt = r->ExplodCount;
			}
			if (r->ExplodEffectCnt == 0)
			{
				r->bExploded = false;
				ExplodeEffect(r);
				++MyHero->Remains;
				r->ExplodEffectCnt = r->ExplodCount;
			}
		}
	}
	// 캐릭터 죽이기
	HeroDeath();
	// 오브젝트 그린거 삭제
	ObjectRemove();

}

void GameManager::BombEffect(Bomb* bomb)
{
	int bx = bomb->GetPos().X;
	int by = bomb->GetPos().Y;
	int rg = MyHero->BombRange;

	for (int x = bx; x < bx + rg + 1; ++x)
	{
		if (Explode(x, by) == true) { break; }
	}
	for (int y = by + 1; y < by + rg + 1; ++y)
	{
		if (Explode(bx, y) == true) { break; }
	}
	for (int x = bx - 1; x > bx - rg - 1; --x)
	{
		if (Explode(x, by) == true) { break; }
	}
	for (int y = by - 1; y > by - rg - 1; --y)
	{
		if (Explode(bx, y) == true) { break; }
	}
}

bool GameManager::Explode(int x, int y)
{
	int RangeCnt = 0;

	for (auto r : Objects)
	{
		if (r->IsCrossed(x, y) == true)
		{
			r->Temp();
			++RangeCnt;
		}
	}
	for (auto r : Monsters)
	{
		if (r->IsCrossed(x, y) == true)
		{
			r->Temp();
			r->Stop();
		}
	}
	for (auto r : Items)
	{
		if (r->IsCrossed(x, y) == true)
		{
			r->Temp();
		}
	}
	for (auto r : Blocks)
	{
		if (r->IsCrossed(x, y) == true)
		{
			r->Temp();
			++RangeCnt;
		}
	}
	for (auto r : MyHero->Bombs)
	{
		if (r->GetOverState() == false)
		{
			if (r->IsCrossed(x, y) == true)
			{
				r->Over();
				r->ExplodCnt = SecondCount;
				BombEffect(r);
				r->bExploded = true;
				++RangeCnt;
			}
		}
	}

	if (0 < x && 0 < y && x < MAP_X - 2 && y < MAP_Y - 1)
	{
		gotoxy(x + X, y + Y);
		cout << "%";
	}

	if (RangeCnt != 0) { return true; }
	return false;
}

void GameManager::ExplodeEffect(Bomb*bomb)
{
	int bx = bomb->GetPos().X;
	int by = bomb->GetPos().Y;
	int rg = MyHero->BombRange;

	for (int x = bx; x < bx + rg + 1; ++x)
	{
		if (RemoveEffect(x, by) == true) { break; }
	}
	for (int y = by + 1;y < by + rg + 1; ++y)
	{
		if (RemoveEffect(bx, y) == true) { break; }
	}
	for (int x = bx - 1; x > bx - rg - 1; --x)
	{
		if (RemoveEffect(x, by) == true) { break; }
	}
	for (int y = by - 1; y > by - rg - 1; --y)
	{
		if (RemoveEffect(bx, y) == true) { break; }
	}
}

bool GameManager::RemoveEffect(int x, int y)
{
	int RangeCnt = 0;

	for (auto r : Objects)
	{
		if (r->IsCrossed(x, y) == true)
		{
			r->Over();
			++RangeCnt;
		}
	}
	for (auto r : Monsters)
	{
		if (r->IsCrossed(x, y) == true)
		{
			r->Over();
		}
	}
	for (auto r : Items)
	{
		if (r->IsCrossed(x, y) == true)
		{
			r->Over();
		}
	}
	for (auto r : Blocks)
	{
		if (r->IsCrossed(x, y) == true)
		{
			r->Over();
			Item*pItem = MakeItem(x, y);

			if (pItem != nullptr)
			{
				Items.push_back(pItem);
			}
			++RangeCnt;
		}
	}

	if (0 < x && 0 < y&&x < MAP_X - 2 && y < MAP_Y - 1)
	{
		gotoxy(x + X, y + Y);
		cout << " ";
	}

	if (RangeCnt != 0) { return true; }
	return false;
}

Item* GameManager::MakeItem(int x, int y)
{
	Item* item = nullptr;
	float r = (float)rand() / (float)RAND_MAX;

	if (r < 0.05f)
	{
		item = new Item(x, y, eType::SPEED_UP);
	}
	else if (r < 0.1f)
	{
		item = new Item(x, y, eType::COUNT_UP);
	}
	else if (r < 0.15f)
	{
		item = new Item(x, y, eType::RANGE_UP);
	}
	else
	{
		item=nullptr;
	}

	return item;
}

void GameManager::Complete()
{
	delay(2000);
	system("cls");

	if (stage == MaxStageCount)
	{
		cout << "Complate";
		delay(2000);
		SceneMan->ChangeScene(eScene::OverScene);
		return;
	}

	cout << "Next Stage";
	delay(2000);
	system("cls");
	++stage;
	SceneMan->ChangeScene(eScene::GameScene);
}

void GameManager::Delete()
{
	for (int i = 0; i < MAP_Y; ++i)
	{
		SAFE_DELETE_ARR(pMap[i]);
	}
	SAFE_DELETE_ARR(pMap);
	for (auto r : MyHero->Bombs)	 { SAFE_DELETE(r); }
	for (auto r : Objects)			 { SAFE_DELETE(r); }
	for (auto r : Monsters)			 { SAFE_DELETE(r); }
	for (auto r : Blocks)			 { SAFE_DELETE(r); }
	for (auto r : Items)		  	 { SAFE_DELETE(r); }
	for (auto r : Walls)			 { SAFE_DELETE(r); }

}

void GameManager::Loge()
{
	// 왼쪽 로그
	gotoxy(X - 35, Y + 5);
	cout << "왼쪽";
	gotoxy(X - 35, Y + 6);
	cout <<"스피드 : " << MyHero->Speed << "     ";
	gotoxy(X - 35, Y + 7);
	cout << "폭탄 개수 : " << MyHero->BombCnt << "     ";
	gotoxy(X - 35, Y + 8);
	cout << "폭탄 범위 : " << MyHero->BombRange << "     ";
	gotoxy(X - 35, Y + 9);
	cout << "폭탄 사이즈 : " << MyHero->Bombs.size() << "     ";
	gotoxy(X - 35, Y + 10);
	cout << "아이템 사이즈 : " << Items.size() << "     ";

	// 오른쪽 로그
	gotoxy(X + 65, Y + 5);
	cout << "오른쪽";

	// 위쪽 로그
	gotoxy(X + 5, Y - 3);
	cout << "위쪽";
	gotoxy(X + 10, Y - 3);
	cout << "타이머";

	// 아래쪽 로그
	gotoxy(X + 5, Y + 27);
	cout << "아래쪽";
}

void GameManager::ObjectRemove()
{
	for (int i = 0; i < Objects.size(); ++i)
	{
		if (Objects[i]->GetOverState() == true)
		{
			SAFE_DELETE(Objects[i]);
			Objects.erase(Objects.begin() + i);

			i = 0;
		}
	}
	for (int i = 0; i < Monsters.size();++i)
	{
		if (Monsters[i]->GetOverState() == true)
		{
			SAFE_DELETE(Monsters[i]);
			Monsters.erase(Monsters.begin()+i);

			i = 0;
		}
	}
	for (int i = 0; i < Blocks.size(); ++i)
	{
		if (Blocks[i]->GetOverState() == true)
		{
			SAFE_DELETE(Blocks[i]);
			Blocks.erase(Blocks.begin() + i);

			i = 0;
		}
	}
	for (int i = 0; i < Items.size(); ++i)
	{
		if (Items[i]->GetOverState() == true)
		{
			SAFE_DELETE(Items[i]);
			Items.erase(Items.begin() + i);

			i = 0;
		}
	}
}

void GameManager::HeroDeath()
{
	if (Monsters.size() == 0) { Complete(); }
	if (MyHero->GetOverState() == true)
	{
		delay(2000);
		SceneMan->ChangeScene(eScene::OverScene);
	}
}