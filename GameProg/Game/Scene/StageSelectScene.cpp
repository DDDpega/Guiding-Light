#include "Framework.h"
StageSelectScene::StageSelectScene(Game* gameInstance)
	:Scene(gameInstance, "ゲームセレクト")
{

}

StageSelectScene::~StageSelectScene()
{

}

void StageSelectScene::Initialize()
{
	Scene::Initialize();

	//UIを表示する
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
