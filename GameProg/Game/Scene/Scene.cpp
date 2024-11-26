#include "Framework.h"


Scene::Scene(const char* name)
	:m_sceneName(name)
	, m_isPause(false)
	, m_isRightFade(false)
{

}

Scene::~Scene()
{

}

void Scene::Initialize()
{
}

void Scene::Update()
{

}

void Scene::Draw()
{
	//DrawFormatString(0, 0, GetColor(255, 255, 255), m_sceneName);
}