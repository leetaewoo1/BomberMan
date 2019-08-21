#pragma once
#include "pch.h"
#include "Scene.h"
#include "GameManager.h"

class GameScene:public Scene
{
public:
	GameScene(SceneManager*a_pParent);

	GameManager* GM;

	virtual ~GameScene();

	// Scene을 통해 상속됨
	virtual eScene GetScene()override;

	virtual void Init()override;
	virtual void Update(float a_fDeltaTime)override;
	virtual void Render()override;

	virtual void KeyInput()override;

};

