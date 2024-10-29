#include "Framework.h"
StageSelectScene::StageSelectScene()
	:Scene("ゲームセレクト")
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
