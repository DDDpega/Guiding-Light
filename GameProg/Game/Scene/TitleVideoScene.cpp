#include "Framework.h"


TitleVideoScene::TitleVideoScene()
	:Scene("タイトルムービーシーン")
{

}

TitleVideoScene::~TitleVideoScene()
{
}

void TitleVideoScene::Initialize()
{
	Scene::Initialize();

	//UIを表示する
	auto videoUI = shared_ptr<TitleVideoUI>(new TitleVideoUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(videoUI);

	m_videoHandle = LoadGraph(VideoInfo::VIDEO_PATH);

	
	
	PlayMovieToGraph(m_videoHandle, DX_MOVIEPLAYTYPE_BCANCEL);

}

void TitleVideoScene::Update()
{
	Scene::Update();
	if (GetMovieStateToGraph(m_videoHandle) == 0) {
		Game::gameInstance->GetSceneMNG()->ChangeSceneFlag(E_SCENE::TITLE);
	}

}

void TitleVideoScene::Draw()
{
	Scene::Draw();
	//元に戻す
	SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
	// ムービー映像を画面いっぱいに描画します
	DrawExtendGraph(0, 0, WINDOW_INFO::GAME_WIDTH, WINDOW_INFO::GAME_HEIGHT, m_videoHandle, FALSE);
}