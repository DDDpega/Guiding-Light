#include "Framework.h"


TitleScene::TitleScene()
	:Scene("タイトルシーン")
	, m_nowcursor(0)
{

}

TitleScene::~TitleScene()
{
}

void TitleScene::Initialize()
{
	Scene::Initialize();

	//UIを表示する
	auto titleUI = shared_ptr<TitleUI>(new TitleUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(titleUI);

}

void TitleScene::Update()
{
	Scene::Update();

}

void TitleScene::Draw()
{
	Scene::Draw();
}