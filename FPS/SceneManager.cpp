#include "pch.h"

#include "Scene.h"
#include "SceneManager.h"
#include "SceneFactory.h"

SceneManager::~SceneManager()
{
	SAFE_DELETE(m_pNowScene);
}

void SceneManager::Init()
{
	ChangeScene(eScene::Scene_First);
}

eScene SceneManager::GetNowScene()
{
	return m_pNowScene->GetScene();
}

void SceneManager::Update(float a_fDeltaTime)
{
	m_pNowScene->Update(a_fDeltaTime);
}

void SceneManager::Render()
{
	m_pNowScene->Render();
}

void SceneManager::KeyInput()
{
	m_pNowScene->KeyInput();
}

void SceneManager::ChangeScene()
{
	if (m_pNowScene->bOver == true)
	{
		eScene etype = m_pNowScene->GetScene();

		switch (etype)
		{
		case eScene::IntroScene: ChangeScene(eScene::GameScene); break;
		case eScene::GameScene: ChangeScene(eScene::OverScene); break;
		case eScene::OverScene: break;
		default: break;
		}
	}
}

void SceneManager::ChangeScene(eScene a_eScene)
{
	SAFE_DELETE(m_pNowScene);

	m_pNowScene = SceneFactory::Make(a_eScene);

	assert((m_pNowScene != nullptr) && "error");

	system("cls");
	m_pNowScene->Init();
}
