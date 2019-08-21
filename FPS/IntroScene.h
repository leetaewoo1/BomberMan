#pragma once
#include "pch.h"
#include "Scene.h"

class IntroScene :public Scene
{
public:
	IntroScene(SceneManager*a_pParent);
	virtual ~IntroScene();

	// Scene을 통해 상속됨
	virtual eScene GetScene()override;
	virtual void Init()override;
	virtual void Update(float a_fDeltaTime)override;
	virtual void Render()override;

	virtual void KeyInput()override;
};

