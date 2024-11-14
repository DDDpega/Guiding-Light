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

	//	m_startText[1] = std::shared_ptr<Picture>(new Picture(Point{ 300, scrY / 2 + 200 }, 0.5, UI::TITLE_LIST[UI::TITLE_TYPE::YES], 0, E_PIVOT::CENTER, E_SORT::SORT_UI, false));
	v = 1;
	

	m_bgm = shared_ptr<Sound>(new Sound(SOUND::BGM_LIST[SOUND::BGM_TYPE::TITLE], Sound::E_Sound::BGM, 0));
	Game::gameInstance->GetSoundMNG()->AddSoundList(m_bgm);

	//UIを表示する
	auto titleUI = shared_ptr<TitleUI>(new TitleUI());
	Game::gameInstance->GetPictureMNG()->AddPicture(titleUI);

	m_bgm->SoundPlay(Sound::LOOP);
}

void TitleScene::Update()
{
	Scene::Update();
	v -= 0.0001f;
	m_bgm->SetPlaySoundVolume(v);

}

void TitleScene::Draw()
{
	Scene::Draw();
}