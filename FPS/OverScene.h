#pragma once
#include "pch.h"
#include "Scene.h"

class OverScene:public Scene
{
	enum{CHANCE=3,YES=121,NO=110,};
public:

	inline static int Chance = CHANCE;

	OverScene(SceneManager* a_pParent);
	virtual ~OverScene();

	// Scene을 통해 상속됨
	virtual eScene GetScene()override;

	virtual void Init()override;
	virtual void Update(float a_fDeltaTime)override;
	virtual void Render()override;

	virtual void KeyInput()override;
};

