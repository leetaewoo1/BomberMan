#include "pch.h"
#include "OverScene.h"


OverScene::OverScene(SceneManager* a_pParent):Scene(a_pParent)
{
}


OverScene::~OverScene()
{
	m_refParent = nullptr;
}

eScene OverScene::GetScene()
{
	return eScene::OverScene;
}

void OverScene::Init()
{
}

void OverScene::Update(float a_fDeltaTime)
{
	if (Chance == 0)
	{
		Render();
		_getch();
		system("cls");
		delay(1000);
		exit(0);
	}
}

void OverScene::Render()
{
	int ConX = CONSOLE_X / 6;
	int ConY = CONSOLE_Y / 3;

	for (int y = 0; y < OVER_Y; ++y)
	{
		for (int x = 0; x < OVER_X; ++x)
		{
			gotoxy(x + ConX, y + ConY);
			cout << GameData::Over[y][x];
		}
	}

	if (Chance != 0)
	{
		gotoxy(CONSOLE_X / 2 - 8, CONSOLE_Y / 2 + 6);
		cout << "WANNA PLAY MORE?";
		gotoxy(CONSOLE_X / 2 - 3, CONSOLE_Y / 2 + 8);
		cout << "Y / N";;
	}
}

void OverScene::KeyInput()
{
	char c = GetKeyInput();

	switch (c)
	{
	case YES:
		--Chance;
		m_refParent->ChangeScene(eScene::IntroScene);
		system("cls");
		delay(1000);
		break;
	case NO:
		system("cls");
		delay(1000);
		exit(0);
		break;
	default:
		break;
	}

}
