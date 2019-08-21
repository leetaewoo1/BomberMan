#pragma once

#include "SceneManager.h"

class Scene
{
public:

	bool bOver = false;


	Scene(SceneManager*a_pParent);
	virtual ~Scene();

	virtual eScene GetScene() = 0;

	virtual void Init();
	virtual void Update(float a_fDeltaTime);
	virtual void Render();
	virtual void KeyInput();

	virtual bool GetState() { return bOver; }
	virtual void Over() { bOver = true; }

protected:

	class SceneManager*m_refParent = nullptr;
};

