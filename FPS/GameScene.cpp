#include "pch.h"
#include "GameScene.h"


GameScene::GameScene(SceneManager* a_pParent) :Scene(a_pParent)
{
	GM = new GameManager;
}


GameScene::~GameScene()
{
	SAFE_DELETE(GM);
	m_refParent = nullptr;
}

eScene GameScene::GetScene()
{
	return eScene::GameScene;
}

void GameScene::Init()
{
	GM->Init();
}

void GameScene::Update(float a_fDeltaTime)
{
	GM->Update(a_fDeltaTime);
}

void GameScene::Render()
{
	GM->Render();
}

void GameScene::KeyInput(){}
