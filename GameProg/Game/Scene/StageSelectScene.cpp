#include "Framework.h"
StageSelectScene::StageSelectScene(Game* gameInstance)
	:Scene(gameInstance, "�Q�[���Z���N�g")
{

}

StageSelectScene::~StageSelectScene()
{

}

void StageSelectScene::Initialize()
{
	Scene::Initialize();

	//UI��\������
	auto stageSelectUI = shared_ptr<StageSelectUI>(new StageSelectUI());
	m_gameInstance->GetPictureMNG()->AddPicture(stageSelectUI, this);
}

void StageSelectScene::Update()
{
	Scene::Update();
}

void StageSelectScene::Draw()
{
	Scene::Draw();
}
