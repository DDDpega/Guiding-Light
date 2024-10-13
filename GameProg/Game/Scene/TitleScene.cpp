#include "Framework.h"


TitleScene::TitleScene(Game* gameInstance)
	:Scene(gameInstance,"タイトルシーン")
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
	m_gameInstance->GetPictureMNG()->AddPicture(titleUI, this);

}

void TitleScene::Update()
{
	Scene::Update();

}

void TitleScene::Draw()
{
	Scene::Draw();
}