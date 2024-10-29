#include "Framework.h"
StageSelectScene::StageSelectScene()
	:Scene("�Q�[���Z���N�g")
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
	Game::gameInstance->GetPictureMNG()->AddPicture(stageSelectUI);
}

void StageSelectScene::Update()
{
	Scene::Update();
}

void StageSelectScene::Draw()
{
	Scene::Draw();
}
