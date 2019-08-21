#include "pch.h"
#include "SceneFactory.h"
#include "GameScene.h"
#include "OverScene.h"
#include "SceneManager.h"
#include "IntroScene.h"

Scene* SceneFactory::Make(eScene a_eScene)
{
	SceneManager* pParent = SceneMng();
	Scene* pMakedScene = nullptr;

	switch (a_eScene)
	{
	case eScene::IntroScene: pMakedScene = new IntroScene(pParent); break;
	case eScene::GameScene: pMakedScene = new GameScene(pParent); break;
	case eScene::OverScene: pMakedScene = new OverScene(pParent); break;
	default: assert(false && "arg error"); break;
	}

	return pMakedScene;
}