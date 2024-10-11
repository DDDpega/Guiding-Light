#include "Scene.h"
#include"Picture.h"
#include "SceneManeger.h"
#include "PictureManeger.h"
#include "include.h"

Scene::Scene(Game* gameInstance,const char* name)
	:m_sceneName(name)
	,m_isPause(false)
	,m_gameInstance(gameInstance)
{

}

Scene::~Scene()
{

}

void Scene::Initialize()
{
	//��ʂ�X�T�C�Y�̎擾
	GetScreenState(&screenX, &screenY, nullptr);
}

void Scene::Update()
{

}

void Scene::Draw()
{
	DrawFormatString(0, 0, GetColor(255, 255, 255), m_sceneName);
}