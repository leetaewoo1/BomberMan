#pragma once
#include "pch.h"

class SceneFactory
{
public:
	static class Scene* Make(eScene a_eScene);
};

