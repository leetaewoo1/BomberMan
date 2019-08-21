#include "pch.h"
#include "IntroScene.h"


IntroScene::IntroScene(SceneManager*a_pParent) :Scene(a_pParent)
{
}


IntroScene::~IntroScene()
{
	m_refParent = nullptr;
}

eScene IntroScene::GetScene()
{
	return eScene::IntroScene;
}

void IntroScene::Init()
{

}

void IntroScene::Update(float a_fDeltaTime)
{

}

void IntroScene::Render()
{
	int ConX = CONSOLE_X / 6;
	int ConY = CONSOLE_Y / 3;

	for (int y = 0; y < INTRO_Y; ++y)
	{
		for (int x = 0; x < INTRO_X; ++x)
		{
			gotoxy(x + ConX, y + ConY);
			cout << GameData::Intro[y][x];
		}
	}
}

void IntroScene::KeyInput()
{
	_getch();
	Over();
}
